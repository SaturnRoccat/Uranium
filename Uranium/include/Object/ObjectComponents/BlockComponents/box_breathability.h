#pragma once
#include "BlockComponent.h"
#if URANIUM_TARGET_FORMAT_VERSION <= 11941
namespace Uranium
{
	namespace Creation
	{
		namespace Components
		{
			namespace BlockComponents
			{
				// Deprecated
				class box_breathability : public BlockComponent
				{
				private:
					std::string val;
				public:
					DEPRECATED("This component is deprecated and will be removed in the future.")
					box_breathability(const std::string& val = "solid") : BlockComponent("minecraft:breathability"), val(val) {}
					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override;
				};

			}
		}
	};
};
#endif