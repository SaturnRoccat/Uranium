#pragma once
#include <Object/ObjectComponents/BlockComponents/BlockComponent.h>
#include <Utils/RandomTypes.h>
namespace Uranium
{
	namespace Creation
	{
		namespace Components
		{
			namespace BlockComponents
			{
				class CollisionBox : public BlockComponent
				{
				private:
					Vec3i origin;
					Vec3i size;
				public:
					CollisionBox(Vec3i origin = Vec3i(-8, 0, -8), Vec3i size = Vec3i(16, 16, 16)) : origin(origin), size(size), BlockComponent("minecraft:collision_box", {Experiments::HolidayCreatorFeatures}) {}

					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override;
				};
			}
		}
	}
}