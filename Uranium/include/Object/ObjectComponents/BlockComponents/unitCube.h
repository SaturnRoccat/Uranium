#pragma once
#include "BlockComponent.h"

namespace Uranium
{
	namespace Creation
	{
		namespace Components
		{
			namespace BlockComponents
			{
				class UnitCube : public BlockComponent
				{
				public:
					UnitCube() : BlockComponent("minecraft:unit_cube") {}
					~UnitCube() {}

					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override
					{
						rapidjson::Value emptyObject(rapidjson::kObjectType);
						writeDoc->AddMember("minecraft:unit_cube", emptyObject, allocator);
					}

				};
			}
		}
	}
}