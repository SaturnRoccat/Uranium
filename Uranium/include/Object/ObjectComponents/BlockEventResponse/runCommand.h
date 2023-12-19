#pragma once
#include "BlockEventResponse.h"

namespace Uranium
{
	namespace Creation
	{
		namespace Events
		{
			namespace BlockEvent
			{
				class RunCommand : public BlockEventResponse
				{
				private:
					std::string command = "NONE";
					std::vector<std::string> commandArray;
					std::string target;
				public:
					RunCommand(
						ConstStringRef command,
						ConstStringRef target = "self"
					) : command(command), target(target), BlockEventResponse("run_command") {}
					RunCommand(
						std::vector<std::string>& commandArray,
						ConstStringRef target = "self"
					) : commandArray(commandArray), target(target), BlockEventResponse("run_command") {}

					void WriteToEventJson(rapidjson::Value* eventJson, rapidjson::MemoryPoolAllocator<>& allocator) override
					{
						rapidjson::Value commandJson;
						if (command == "NONE")
						{
							RJ_STL_V_A_EX(cmd, commandArray, allocator, RJ_STL_S)
							commandJson.AddMember("command", cmd, allocator);
						}
						else
						{
							commandJson.AddMember("command", RJ_STL_S(command), allocator);
						}
						SET_IF_NOT_DEFAULT_EX(target, "self", commandJson, allocator, "target", RJ_STL_S, .)
						eventJson->AddMember("run_command", commandJson, allocator);
					}
				};
			}
		}
	}
}