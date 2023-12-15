#pragma once
#include <vector>
#include <string>
#include <tuple>
#include "../../../BlockStates.h"
#include "Utils/RandomTypes.h"

namespace Uranium
{
	namespace Creation
	{
		namespace Components
		{
			namespace BlockComponents
			{
				namespace SubClasses
				{
					class placementFilterData
					{
					public:
						const std::string name;
						std::vector<std::pair<BlockStates::BlockStates, std::string>> states;
						const std::string tags;
					public:
						placementFilterData(ConstStringRef name, const std::vector<std::pair<BlockStates::BlockStates, std::string>>& states, ConstStringRef tags = "1") : name(name), states(states), tags(tags) {}
					};
				}
			}
		}
	}
}