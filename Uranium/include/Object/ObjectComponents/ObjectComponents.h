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

		/**
		* @brief The base class for all object components
		* This class is the base class that all components that get added to objects should inherit from.
		*/
		class ObjectComponent
		{
		public:
			std::string componentName = "";
			std::vector<Experiments> requiredExperiments = { Experiments::None };
			const bool skipInCompiliation = false;
		public:
			virtual void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) = 0; // We use then 
			ObjectComponent(const char* name, std::vector<Experiments> requiredExperiments = { Experiments::None }, bool skipCompilation = false) : componentName(name), requiredExperiments(requiredExperiments), skipInCompiliation(skipCompilation) {}
		};
	}
}