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
				class SpawnLoot : public BlockEventResponse
				{
				private:
					std::string lootPath;
				public:
					SpawnLoot(std::string lootPath) : lootPath(lootPath), BlockEventResponse("spawn_loot") {}
				
					void WriteToEventJson(rapidjson::Value* eventJson, rapidjson::MemoryPoolAllocator<>& allocator)
					{
						rapidjson::Value lootTableObject(rapidjson::kObjectType);
						lootTableObject.AddMember("table", RJ_STL_S(lootPath), allocator);
						eventJson->AddMember("spawn_loot", lootTableObject, allocator);
					}
				};
			}
		}
	}
}