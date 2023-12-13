#pragma once
#include "Utils/macros.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <assert.h>
#include <type_traits>

namespace Uranium
{
	/**
	* Creation is the namespace that holds all the classes and functions that are used to create Add-ons with Uranium.
	*/
	namespace Creation 
	{
		template <typename RegisteryType>
		class ObjectRegistery
		{
		private:
			// A place to register objects before compilation.
			std::unordered_map<std::string, RegisteryType*> m_localRegistery;
		public:

			/**
			* This function allows you to register objects that get dynamically created by the program. This allows for the creation of objects dynamically.
			* This lets you generate 1000s of objects without having to create them all in the code.
			* @param object The object to register.
			* @param name The name of the object. If this is empty, then the name of the object will be used.
			* @return void
			*/
			template <typename objectType>
			void registerDynamicObject(objectType* object, std::string& name = "")
			{
				// Make sure that the object is a child of the registery type.
				static_assert(std::is_base_of<RegisteryType, objectType>::value, "The object you are trying to register is not a child of the registery type."); 

				// If the name is empty, then we will use the name of the object.
				if (name == "")
				{
					name = TYPEOF(object);
				}
				m_localRegistery[name] = object;
			}

			/**
			* This function allows you to register objects that get statically created by the program. This function calls the default constructor of the object.
			* This means it is not possible to dynamically create objects with this function. This is meant to allow you to register objects that are created at compile time.
			* @param name The name of the object. If this is empty, then the name of the object will be used.
			* @return void
			*/
			template <typename objectType>
			constexpr void registerStaticObject(std::string name = "")
			{
				// Make sure that the object is a child of the registery type.
				static_assert(std::is_base_of<RegisteryType, objectType>::value, "The object you are trying to register is not a child of the registery type.");

				// If the name is empty, then we will use the name of the object.
				if (name == "")
				{
					name = TYPEOF(objectType);
				}
				m_localRegistery[name] = new objectType();
			}
		private:
		};
	} // namespace Creation
} // namespace Uranium