#pragma once
#include "BlockEventResponse.h"
#include <any> // Again i hate this but i need it for the blockstate
#include <string>

namespace Uranium
{
	namespace Creation
	{
		namespace Events
		{
			namespace BlockEvent
			{
				class SetBlockState : public BlockEventResponse
				{
				private:
					std::vector<std::pair<std::string, std::any>>& BlockStates;
				public:
					SetBlockState(std::vector<std::pair<std::string, std::any>>& BlockStates)
						: BlockStates(BlockStates), BlockEventResponse("set_block_state") {}

					void WriteToEventJson(rapidjson::Value* eventJson, rapidjson::MemoryPoolAllocator<>& allocator)
					{
						rapidjson::Value blockStateJson(rapidjson::kObjectType);
						for (auto& blockState : BlockStates)
						{
							if (blockState.second.type() == typeid(int))
							{
								blockStateJson.AddMember(RJ_STL_S(blockState.first), rapidjson::Value(std::any_cast<int>(blockState.second)), allocator);
							}
							else if (blockState.second.type() == typeid(float))
							{
								blockStateJson.AddMember(RJ_STL_S(blockState.first), rapidjson::Value(std::any_cast<float>(blockState.second)), allocator);
							}
							else if (blockState.second.type() == typeid(bool))
							{
								blockStateJson.AddMember(RJ_STL_S(blockState.first), rapidjson::Value(std::any_cast<bool>(blockState.second)), allocator);
							}
							else if (blockState.second.type() == typeid(std::string))
							{
								blockStateJson.AddMember(RJ_STL_S(blockState.first), RJ_STL_S(std::any_cast<std::string>(blockState.second)), allocator);
							}
						}
						eventJson->AddMember("set_block_state", blockStateJson, allocator);
					}
				};
			}
		}
	}
}