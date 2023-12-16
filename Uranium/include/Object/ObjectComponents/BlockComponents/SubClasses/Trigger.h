#pragma once
#include <string>

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
					class Trigger
					{
					public:
						std::string condition = "";
						std::string event = "set_block_state";
						std::string target = "self";
					public:
						Trigger(std::string condition, std::string event, std::string target)
							: condition(condition), event(event), target(target) {}

					};
				}
			}
		}
	}
}