#pragma once
#include "BlockComponent.h"
#include "SubClasses/materialInstanceSegment.h"


namespace Uranium
{
	namespace Creation
	{
		namespace Components
		{
			namespace BlockComponents
			{
				class MaterialInstances : public BlockComponent
				{
				private:
					std::vector<SubClasses::materialInstanceSegment> materialInstances;

				public:
					MaterialInstances(const std::vector<SubClasses::materialInstanceSegment>& materialInstanceTargets) : materialInstances(materialInstanceTargets), BlockComponent("MaterialInstances") {}
					~MaterialInstances() {}

					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override;
				};
			}
		}
	}
}