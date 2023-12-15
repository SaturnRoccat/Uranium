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
				class Geometry : public BlockComponent
				{
				private:
					const std::string name;
				public:
					Geometry(const std::string& name = "minecraft:geometry.full_block") : BlockComponent("geometry"), name(name) {}
					~Geometry() {}

					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override;
				};
			}
		}
	}
}