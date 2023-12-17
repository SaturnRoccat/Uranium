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
				class DestructibleByMining : public BlockComponent
				{
				protected:
					bool __initalized = false;
				private:
					bool isDestructibleByExplosion = true; // 241 is undefined
					float resistance = -1; // -1 means undefined
				public:
					DestructibleByMining(bool isDestructibleByExplosion = true) : isDestructibleByExplosion(isDestructibleByExplosion), __initalized(true), BlockComponent("destructible_by_mining") {}
					DestructibleByMining(float secondsToDestroy) : BlockComponent("destructible_by_mining"), resistance(secondsToDestroy) {}
					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override;// Never Ever call this function
				};
			}
		}
	}
}