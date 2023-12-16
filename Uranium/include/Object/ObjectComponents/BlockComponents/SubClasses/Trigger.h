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

						void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator, const std::string& triggerName )
						{
							rapidjson::Value trigger(rapidjson::kObjectType);
							trigger.AddMember("condition", rapidjson::StringRef(this->condition.c_str()), allocator);
							trigger.AddMember("event", rapidjson::StringRef(this->event.c_str()), allocator);
							trigger.AddMember("target", rapidjson::StringRef(this->target.c_str()), allocator);
							writeDoc->AddMember(RJ_STL_S(triggerName), trigger, allocator);
						}
					};
				}
			}
		}
	}
}