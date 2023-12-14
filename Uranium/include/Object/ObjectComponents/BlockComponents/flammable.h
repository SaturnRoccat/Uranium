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
				class Flammable : public BlockComponent
				{
				protected:
					bool __inited = false;
				private:
					int catchChanceModifier = 0;
					int destroyChanceModifier = 0;
					bool canCatchFire = true;
				public:
					Flammable(bool canCatchFire = true) : canCatchFire(canCatchFire), __inited(true), BlockComponent("flammable") {}
					Flammable(int catchChanceModifier = 5,
								int destroyChanceModifier = 20) : catchChanceModifier(catchChanceModifier),
						destroyChanceModifier(destroyChanceModifier),
						canCatchFire(canCatchFire),
						BlockComponent("flammable") {}
					~Flammable() {}

					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override;
				};
			}
		}
	}
}