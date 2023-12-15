#pragma once
#include "BlockComponent.h"
#include "SubClasses/placementFilterData.h"
namespace Uranium
{
	namespace Creation
	{
		namespace Components
		{
			namespace BlockComponents
			{
				class PlacementFilter : public BlockComponent
				{
				private:
					std::vector<std::string> allowedFaces;
					std::vector<SubClasses::placementFilterData> blockFilter;
				public:
					PlacementFilter(const std::vector<std::string>& allowedFaces, std::vector<SubClasses::placementFilterData> blockFilter = {}): 
						allowedFaces(allowedFaces), blockFilter(blockFilter), BlockComponent("minecraft:placement_filter") {}

					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override;
				};
			}
		}
	}
}