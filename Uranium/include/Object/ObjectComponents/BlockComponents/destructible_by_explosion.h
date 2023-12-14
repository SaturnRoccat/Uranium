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
				class DestructibleByExplosion : public BlockComponent
				{
				protected:
					bool __initalized = false;
				private:
					bool isDestructibleByExplosion = 241; // 241 is undefined
					int resistance = -1; // -1 means undefined
				public:
					DestructibleByExplosion(bool isDestructibleByExplosion = true) : isDestructibleByExplosion(isDestructibleByExplosion), __initalized(true), BlockComponent("destructible_by_explosion") {}
					DestructibleByExplosion(int resistance) : BlockComponent("destructible_by_explosion"), resistance(resistance) {}
					~DestructibleByExplosion() {}
					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override;// Never Ever call this function
				};
			}
		}
	}
}