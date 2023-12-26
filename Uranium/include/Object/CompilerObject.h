#pragma once

#include "ObjectComponents/ObjectComponents.h"
#include <vector>
#include "../Utils/RandomTypes.h"
#include "UraniumGlobals.h"
#include "Registeries/ObjectRegistery.h"
#include "../Utils/RapidProxy.h"
namespace Uranium
{
	namespace Creation
	{
		/**
		* BaseObject is the base class for all objects in Uranium.
		* This class represents a single object in Uranium
		* @tparam RegisteryType The type of the registery that this object will use
		* @param objectName The name of the object
		* This class is abstract and should not be instanced directly unless you are making a child class.
		*/
		template <typename RegisteryType>
		class BaseObject
		{
		public:
			std::string objectName;
			FormatVersion formatVersion = GlobalFormatVersion; 
			Uranium::Creation::ObjectRegistry<RegisteryType*> objectRegistery; 
			rapidjson::Document jsonRepresentation;
			const std::string folderName; // This is the folder that the object gets saved in on serialization
		public:
			BaseObject(const char* name) {
				objectName = name;
			}
			template <typename ComponentType>
			void addComponent(ComponentType* component) {
				objectRegistery.registerDynamicObject(component, component->componentName);
			} 

			template <typename ComponentType>
			void addComponent(const char* name = "")
			{
				objectRegistery.registerStaticObject<ComponentType>(name);
			}
			
			virtual void getAsJsonData(rapidjson::Document* doc) = 0;

		};

		template <typename ComponentRegisteryType, typename EventRegisteryType>
		class BaseObjectWithEvents : public BaseObject<ComponentRegisteryType>
		{
		public:
			Uranium::Creation::ObjectRegistry<EventRegisteryType*> eventRegistery;
		public:
			BaseObjectWithEvents(const char* name) : BaseObject<ComponentRegisteryType>(name) {}
			virtual void getAsJsonData(rapidjson::Document* doc) = 0;

			template <typename EventType>
			void addEvent(EventType* event) {
				eventRegistery.registerDynamicObject(event, event->eventName);
			}

			template <typename EventType>
			void addEvent(const char* name = "")
			{
				eventRegistery.registerStaticObject<EventType>(name);
			}
		};
	} // namespace Creation
} // namespace Uranium