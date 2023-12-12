#pragma once
#include <SimdJson/simdjson.h>

namespace Uranium
{
	namespace Creation
	{
		class ObjectComponent
		{
		public:
			std::string componentName;
			simdjson::dom::element componentData;
			ObjectComponent(std::string& name, simdjson::dom::element& data) {
				componentName = name;
				componentData = data;
			}
		};
	}
}