#include <Object/ObjectComponents/BlockComponents/placementFilter.h>
#include <Utils/macros.h>

namespace Uranium
{
	namespace Creation
	{
		namespace Components
		{
			namespace BlockComponents
			{
				void PlacementFilter::getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator)
				{
					rapidjson::Value placementFilter(rapidjson::kObjectType);
					RJ_STL_V_A_EX(RJ_AllowedFaces, this->allowedFaces, allocator, Utils::StrToRJ)
					placementFilter.AddMember("allowed_faces", RJ_AllowedFaces, allocator);

					if (this->blockFilter.size() == 0)
					{
						rapidjson::Value blockFilter(rapidjson::kArrayType);

						for (auto& i : this->blockFilter)
						{
							rapidjson::Value RJ_block(rapidjson::kObjectType);

							// Handler of the name of the block key of "name"
							rapidjson::Value RJ_name;
							RJ_name.SetString(RJ_STL_S(i.name), allocator);

							if (i.states.size() != 0)
							{
								rapidjson::Value RJ_states = rapidjson::Value(rapidjson::kObjectType);
								for (auto& j : i.states)
								{
									rapidjson::Value RJ_state;
									RJ_state.SetString(RJ_STL_S(j.second), allocator);

									// This might crash due to getBlockStateName returning a std::string then RJ_STL_S converting it to a rapidjson::StringRef with a c_str call so it might
									// get deleted. until it does im not going to fix it lmfao.
									RJ_states.AddMember(RJ_STL_S(BlockStates::getBlockStateName(j.first)), RJ_state, allocator);
								}
								RJ_block.AddMember("states", RJ_states, allocator);
							}
							SET_IF_NOT_DEFAULT_EX(i.tags, "1", RJ_block, allocator, "tags", Utils::StrToRJ, .)

							blockFilter.PushBack(RJ_block, allocator);
						}
						placementFilter.AddMember("block_filter", blockFilter, allocator);
					}

					writeDoc->AddMember("minecraft:placement_filter", placementFilter, allocator);

				}
			}
		}
	}
}