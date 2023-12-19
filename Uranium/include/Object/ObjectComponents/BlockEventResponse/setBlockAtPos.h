#pragma once
#include "BlockEventResponse.h"
#include "../GlobalSubClasses/blockType.h"

namespace Uranium
{
	namespace Creation
	{
		namespace Events
		{
			namespace BlockEvent
			{
				class SetBlockAtPos : BlockEventResponse
				{
				private:
					SubClasses::BlockType* blkType;
					Vec3i Offset;
				public:
					SetBlockAtPos(SubClasses::BlockType* blkType, Vec3i Offset = {0, 0, 0})
						: blkType(blkType), Offset(Offset), BlockEventResponse("set_block_at_pos") {}
					void WriteToEventJson(rapidjson::Value* eventJson, rapidjson::MemoryPoolAllocator<>& allocator)
					{
						rapidjson::Value setBlock;
						blkType->GetAsJson(&setBlock, allocator);

						RJ_STL_V_A(RJ_Offset, Offset.toArray(), allocator)
						setBlock.AddMember("block_offset", RJ_Offset, allocator);
						eventJson->AddMember("set_block_at_pos", setBlock, allocator);
					}
				};
			}
		}
	}
}