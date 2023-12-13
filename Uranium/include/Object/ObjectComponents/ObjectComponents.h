#pragma once
#include <string>
#include <Utils/RapidProxy.h>
#include <vector>

namespace Uranium
{
	namespace Creation
	{

		enum class Experiments
		{
			None,
			HolidayCreatorFeatures,
		};

		enum class PlacementLocation
		{
			Components,
		};

		struct JsonData
		{
			rapidjson::Value jsonRepresentation;
			PlacementLocation placementLocation;
		};

		/**
		* @brief The base class for all object components
		* This class is the base class that all components that get added to objects should inherit from.
		*/
		class ObjectComponent
		{
		public:
			std::string componentName = "";
			std::vector<Experiments> requiredExperiments = { Experiments::None };
			virtual JsonData getAsJsonData() = 0; // We use then 
			ObjectComponent(const char* name, std::vector<Experiments> requiredExperiments = { Experiments::None }) : componentName(name), requiredExperiments(requiredExperiments) {}
		};
	}
}