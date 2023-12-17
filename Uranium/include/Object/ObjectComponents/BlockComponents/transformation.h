#pragma once
#include "BlockComponent.h"
#include <array>

namespace Uranium
{
	namespace Creation
	{
		namespace Components
		{
			namespace BlockComponents
			{
				class Transformation : public BlockComponent
				{
				private:
					std::array<int, 3> rotation;
					std::array<int, 3> translation;
					std::array<int, 3> scale;
				public:
					Transformation(
						std::array<int, 3> rotation = { 0, 0, 0 },
						std::array<int, 3> translation = { 0, 0, 0 },
						std::array<int, 3> scale = { 1, 1, 1 }
					) : BlockComponent("minecraft:transformation", {Experiments::HolidayCreatorFeatures}),
						rotation(rotation),
						translation(translation),
						scale(scale)
					{}
					~Transformation() {}

					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override;

				};
			}
		}
	}
}