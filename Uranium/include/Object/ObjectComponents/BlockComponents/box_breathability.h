#pragma once
#include "BlockComponent.h"
#if URANIUM_TARGET_FORMAT_VERSION <= 12050
namespace Uranium
{
	namespace Creation
	{
		namespace Components
		{
			namespace BlockComponents
			{
				class box_breathability : public BlockComponent
				{
				private:
					std::string val;
				public:
					box_breathability(const std::string& val = "solid") : BlockComponent("minecraft:breathability"), val(val) {}
					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override;
				};

			}
		}
	};
};
#endif