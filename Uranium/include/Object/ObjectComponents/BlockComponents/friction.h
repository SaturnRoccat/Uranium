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
				class Friction : public BlockComponent
				{
				private:
					const float friction;
				public:
					Friction(const float friction = 0.4f) : friction(friction), BlockComponent("friction") {}

					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override;
				};
			}
		}
	}
}