#pragma once

#include "ObjectComponents/ObjectComponents.h"
#include <vector>
#include "../Utils/RandomTypes.h"
#include "UraniumGlobals.h"
#include <rapidjson/document.h>
#include <Registeries/ObjectRegistery.h>

namespace Uranium
{
	namespace Creation
	{
		template <typename RegisteryType>
		class BaseObject
		{
		public:
			std::string objectName;
			FormatVersion formatVersion = GlobalFormatVersion; 
			Uranium::Creation::ObjectRegistery<RegisteryType*> objectRegistery; 
			rapidjson::Document jsonRepresentation;
			const std::string folderName; // This is the folder that the object gets saved in on serialization
		public:
			BaseObject(const char* name) {
				objectName = name;
			}
			void addComponent(ObjectComponent* component) {
			} 
		};
	} // namespace Creation
} // namespace Uranium