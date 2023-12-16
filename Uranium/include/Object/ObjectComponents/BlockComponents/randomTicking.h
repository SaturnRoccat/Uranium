#pragma once
#include "BlockComponent.h"
#include "SubClasses/Trigger.h"
namespace Uranium
{
	namespace Creation
	{
		namespace Components
		{
			namespace BlockComponents
			{
				class RandomTicking : public BlockComponent
				{
				private:
					SubClasses::Trigger onTick;
				public:
					RandomTicking(SubClasses::Trigger& onTick) : onTick(onTick), BlockComponent("minecraft:random_ticking", { Experiments::HolidayCreatorFeatures }) {}
					~RandomTicking() {}

					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override;
				};
			}
		}
	}
}