#pragma once
#include "BlockEventResponse.h"

namespace Uranium
{
	namespace Creation
	{
		namespace Events
		{
			namespace BlockEvent
			{
				class Teleport : public BlockEventResponse
				{
				private:
					bool avoidWater;
					Vec3f destination;
					bool landOnBlock;
					Vec3f maxRange;
					std::string target;
				public:
					Teleport(bool avoidWater = true, Vec3f destination = Vec3f(0, 0, 0), bool landOnBlock = true, Vec3f maxRange = Vec3f(8.f, 8.f, 8.f), std::string target = "self")
						: avoidWater(avoidWater), destination(destination), landOnBlock(landOnBlock), maxRange(maxRange), target(target), BlockEventResponse("teleport") {}

					void WriteToEventJson(rapidjson::Value* eventJson, rapidjson::MemoryPoolAllocator<>& allocator)
					{
						rapidjson::Value teleport(rapidjson::kObjectType);
						teleport.AddMember("avoid_water", avoidWater, allocator);
						RJ_STL_V_A(destinationRJ, destination.toArray(), allocator)
						teleport.AddMember("destination", destinationRJ, allocator);
						teleport.AddMember("land_on_block", landOnBlock, allocator);
						RJ_STL_V_A(maxRangeRJ, maxRange.toArray(), allocator)
						teleport.AddMember("max_range", maxRangeRJ, allocator);
						teleport.AddMember("target", target, allocator);
						eventJson->AddMember("teleport", teleport, allocator);
					}
				};
			}
		}
	}
}