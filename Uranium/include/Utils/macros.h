#pragma once
#include <typeinfo>
#include <string>

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
* @brief This macro is used to get the name and type of a token.
* *
* * @param x The token to get the name and type of.
* * @return The name and type of the token.
*/
#define TOKEN_NICE_NAME(x) TOKENAME(x) + " (" + TYPEOF(x) + ")"