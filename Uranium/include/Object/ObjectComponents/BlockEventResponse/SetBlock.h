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
				class SetBlock : BlockEventResponse
				{
				private:
					SubClasses::BlockType* blkType;
				public:
					SetBlock(SubClasses::BlockType* blkType)
						: blkType(blkType), BlockEventResponse("set_block") {}
					void WriteToEventJson(rapidjson::Value* eventJson, rapidjson::MemoryPoolAllocator<>& allocator)
					{
						rapidjson::Value setBlock;
						blkType->GetAsJson(&setBlock, allocator);
						eventJson->AddMember("set_block", setBlock, allocator);
					}
				};
			}
		}
	}
}