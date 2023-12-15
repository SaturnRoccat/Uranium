#pragma once
#include "BlockComponent.h"
#include <assert.h>

static_assert("Not implemented dumbass");
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
				public:
					queuedTicking() : BlockComponent("minecraft:queued_ticking") {}
					~queuedTicking() {}

					// void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override;
				};
			}
		}
	}
}