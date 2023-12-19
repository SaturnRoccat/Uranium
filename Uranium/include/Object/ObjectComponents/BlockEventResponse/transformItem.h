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
				class TransformItem : public BlockEventResponse
				{
				private:
					std::string transform;
				public:
					TransformItem(std::string transform) : transform(transform), BlockEventResponse("transform_item") {}
					void WriteToEventJson(rapidjson::Value* eventJson, rapidjson::MemoryPoolAllocator<>& allocator)
					{
						// create the transform object
						rapidjson::Value transformObject(rapidjson::kObjectType);
						// add the transform string
						transformObject.AddMember("transform",RJ_STL_S(transform), allocator);
						// add the transform object to the event object
						eventJson->AddMember("transform_item", transformObject, allocator);
					}
				};
			}
		}
	}
}