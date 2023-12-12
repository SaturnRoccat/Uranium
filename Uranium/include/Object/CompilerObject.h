#pragma once
#include <SimdJson/simdjson.h>
#include "ObjectComponents/ObjectComponents.h"
#include <vector>
#include "../Utils/RandomTypes.h"
#include "UraniumGlobals.h"

namespace Uranium
{
	namespace Creation
	{
		class BaseObject
		{
		public:
			std::string objectName;
			FormatVersion formatVersion = GlobalFormatVersion;
			simdjson::dom::element objectData; // Whole data
			std::vector<ObjectComponent*> components;
		public:
			virtual simdjson::dom::element getObjectData() = 0;
			BaseObject(std::string& name) {
				objectName = name;
			}
			void addComponent(ObjectComponent* component) {
				components.push_back(component); // We store pointers to allow for polymorphism
			}
		};
	} // namespace Creation
} // namespace Uranium