#pragma once
#include "BlockComponent.h"
#include <assert.h>
#include "SubClasses/Trigger.h"

namespace Uranium
{
	namespace Creation
	{
		namespace Components
		{
			namespace BlockComponents
			{
				class queuedTicking : public BlockComponent
				{
				private:
					std::vector<int> intervalRange;
					bool looping = true;
					SubClasses::Trigger onTick;
				public:
					queuedTicking(const std::vector<int>& intervalRange, SubClasses::Trigger onTick, bool looping = true) :
						intervalRange(intervalRange),
						looping(looping),
						onTick(onTick),
						BlockComponent("minecraft:queued_ticking", {Experiments::HolidayCreatorFeatures}) {}
					~queuedTicking() {}

					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override;
				};
			}
		}
	}
}