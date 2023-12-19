#pragma once
#include <typeinfo>
#include <string>
#include <assert.h>
#include <type_traits>
#include <Logger/Logger.h>
#include <UraniumGlobals.h>
#include <Utils/UtilFunctions.h>
#include <tuple> // We are going to abuse tuples for this.
#ifndef DEMANGLE_NAME_BUFFER_SIZE 
	#define DEMANGLE_NAME_BUFFER_SIZE 1024
#endif
// Checks if the compiler is GCC, G++, or Clang.
// If it is, it includes the cxxabi header.
// This allows us to get the demangled name of a type.
#ifdef __GUNC__ 
	#include <cxxabi.h>
#endif
#ifdef __GNUG__
	#include <cxxabi.h>
#endif
#ifdef __clang__
	#include <cxxabi.h>
#endif

#ifdef NDEBUG
#else
#define URANIUM_DEBUG
#endif


// Checks if the compiler is ran on Windows.
#ifdef _WIN32 
	#define COMPILER_WINDOWS
#endif

// If the compiler is ran on Windows, then we include the Windows header.
// This allows us to get the demangled name of a type.
#ifdef COMPILER_WINDOWS
    #include <Windows.h>
    #include <dbghelp.h>
    #pragma comment(lib, "dbghelp.lib")
	static std::string DemangleMSVCName(const char* mangledName) {
		char buffer[DEMANGLE_NAME_BUFFER_SIZE];
		UnDecorateSymbolName(mangledName, buffer, DEMANGLE_NAME_BUFFER_SIZE, UNDNAME_COMPLETE);
		return std::string(buffer);
	}
#endif

/**
* @brief This macro is used to get the name of a token.
* * 
* * @param x The token to get the name of.
* * @return The name of the token.
*/
#define TOKENAME(x) #x 

/**
* @brief This macro is used to get the type of a token.
* *
* * @param x The token to get the type of.
* * @return The type of the token.
*/
#if defined(__GNUC__) || defined(__GNUG__) || defined(__clang__)
	#define TYPEOF(x) abi::__cxa_demangle(typeid(x).name(), nullptr, nullptr, nullptr)
#else
	#ifdef COMPILER_WINDOWS
		#define TYPEOF(x) DemangleMSVCName(typeid(x).name())
	#else
		#define TYPEOF(x) typeid(x).name()
	#endif
#endif

/**
* @brief This macro is used to mark a function as deprecated.
* * We use this instead of the [[deprecated]] attribute because it is not supported on all compilers. so we only use it if we dont know what compiler we are using.
* * @param x The message to display when the function is called.
* * @return void
*/
#if defined(__GNUC__) || defined(__GNUG__) || defined(__clang__)
	#define DEPRECATED(x) __attribute__((deprecated(x)))
#elif defined(_MSC_VER)
	#define DEPRECATED(x) __declspec(deprecated(x))
#else
	#define DEPRECATED(x) [[deprecated(x)]]
#endif

/**
* @brief This macro is used to get the name and type of a token.
* *
* * @param x The token to get the name and type of.
* * @return The name and type of the token.
*/
#define TOKEN_NICE_NAME(x) std::string(TOKENAME(x)) + " (" + TYPEOF(x) + ")"

/**
* @brief This macro is used to check if a child is a child of a parent at compile time will static_assert if it is not.
* *
* * @param child The child to check.
* * @param parent The parent to check.
* * @return void
* *
*/
#define IS_CHILD_OF(child, parent) static_assert(std::is_base_of<parent, child>::value, "The Child of Type " + #child + " is not a child of the Parent of Type " + #parent + ".");

/**
* @brief This macro is used to pring messages when in debug mode.
*/
#ifdef URANIUM_DEBUG
#define DEBUG_PRINT(x, ...) Uranium::Logs::Logger::Info(x, __VA_ARGS__)
#else
	#define DEBUG_PRINT(xm, ...)
#endif

/**
* @brief This macro is used to run code when in debug mode.
*/
#ifdef URANIUM_DEBUG
#define DEBUG_CODE(x) x
	#else
#define DEBUG_CODE(x)
#endif

/**
* @brief This macro is used to convert a STL string into a rapidjson string value.
* @Deprecated Use RJ_STL_S instead.
*/
#define RJ_STL_V(x, allocator) rapidjson::Value(x.c_str(), x.size(), allocator)

/**
* @brief This macro is used to convert a STL string into a rapidjson string reference.
*/
#define RJ_STL_S(x) rapidjson::StringRef(x.c_str(), x.size())

/**
* @brief This macro is used to convert a STL vector into a rapidjson array value.
* * @param name The name of the array.
* * @param x The vector to convert.
* * @param allocator The allocator to use.
* * @return void
*/
#define RJ_STL_V_A(name, x, allocator)\
rapidjson::Value name(rapidjson::kArrayType);\
for (auto& i : x) {\
	name.PushBack(i, allocator);\
}

/**
* @brief This macro is used to convert a STL vector into a rapidjson array value with a convertion call.
* * @param name The name of the array.
* * @param x The vector to convert.
* * @param allocator The allocator to use.
* * @param ConvertionCall The call to convert the type.
* * @return void
* 
*/
#define RJ_STL_V_A_EX(name, x, allocator, ConvertionCall)\
rapidjson::Value name(rapidjson::kArrayType);\
for (auto& i : x) {\
	name.PushBack(ConvertionCall(i), allocator);\
}

/**
* This is an internal macro used for quick creation of components. That have a single type.
*/
#define COMPONENT_DEFINE_SINGLE_TYPE(name, type, inheritComponent, componentName, deepNamespace, defaultValue)\
namespace Uranium{namespace Creation{namespace Components{namespace deepNamespace{\
				class name : public inheritComponent\
				{\
				public:\
					type value = defaultValue;\
					name(const type& value = defaultValue) : value(value), inheritComponent(componentName) {}\
					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override\
					{\
						rapidjson::Value value(this->value);\
						writeDoc->AddMember(componentName, value, allocator);\
					}\
				};\
			}}}}

/**
* This is an internal macro used for quick creation of components. That have a single type. That allows for data to be passed to the constructor.
*/
#define COMPONENT_DEFINE_SINGLE_TYPE_VA(name, type, inheritComponent, componentName, deepNamespace, defaultValue, ...)\
namespace Uranium{namespace Creation{namespace Components{namespace deepNamespace{\
				class name : public inheritComponent\
				{\
				public:\
					type value = defaultValue;\
					name(const type& value = defaultValue) : value(value), inheritComponent(componentName, __VA_ARGS__) {}\
					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override\
					{\
						rapidjson::Value value(this->value);\
						writeDoc->AddMember(componentName, value, allocator);\
					}\
				};\
			}}}}

/**
* * This is an internal macro used for quick creation of components. That have a single type. That allows for data to be passed to the constructor. And a convertion call.
*/
#define COMPONENT_DEFINE_SINGLE_TYPE_VA_EX(name, type, inheritComponent, componentName, deepNamespace, defaultValue, convertionCall, ...)\
namespace Uranium{namespace Creation{namespace Components{namespace deepNamespace{\
				class name : public inheritComponent\
				{\
				public:\
					type value = defaultValue;\
					name(const type& value = defaultValue) : value(value), inheritComponent(componentName, __VA_ARGS__) {}\
					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override\
					{\
						rapidjson::Value value(convertionCall(this->value));\
						writeDoc->AddMember(componentName, value, allocator);\
					}\
				};\
				}}}}

/**
* This is an internal macro used for quick creation of components. That have a single type. And a convertion call.
*/
#define COMPONENT_DEFINE_SINGLE_TYPE_EX(name, type, inheritComponent, componentName, deepNamespace, defaultValue, convertionCall)\
namespace Uranium{namespace Creation{namespace Components{namespace deepNamespace{\
				class name : public inheritComponent\
				{\
				public:\
					type value = defaultValue;\
					name(const type& value = defaultValue) : value(value), inheritComponent(componentName) {}\
					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override\
					{\
						rapidjson::Value value(convertionCall(this->value));\
						writeDoc->AddMember(componentName, value, allocator);\
					}\
				};\
			}}}}

/**
* This is an internal macro used to set a value in a rapidjson document if it is not the default value.
*/
#define SET_IF_NOT_DEFAULT(value, defaultValue, writeDoc, allocator, name, operatorToCallWith)\
if (value != defaultValue) {\
	rapidjson::Value valueT(value);\
	writeDoc operatorToCallWith AddMember(name, valueT, allocator);\
}

/**
* This is an internal macro used to set a value in a rapidjson document if it is not the default value. But this allows for a convertion call.
*/
#define SET_IF_NOT_DEFAULT_EX(value, defaultValue, writeDoc, allocator, name, convertionCall, operatorToCallWith)\
if (value != defaultValue) {\
	rapidjson::Value valueT(convertionCall(value));\
	writeDoc operatorToCallWith AddMember(name, valueT, allocator);\
}

#define COMPONENT_DEFINE_ADVANCED(Name, InheritComponent, ComponentName, VariableDeclarations, ConvertionCallBody, defaltConstructorDeclarations)\
namespace Uranium{namespace Creation{namespace Components{namespace Name{\
				class Name : public InheritComponent\
				{\
				private:\
					VariableDeclarations\
				public:\
                    Name(defaltConstructorDeclarations) : InheritComponent(ComponentName) {}\
					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override\
					{\
						ConvertionCallBody\
					}\
				};\
			}}}}
