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
				class Swing : public BlockEventResponse 
				{
				public:
					Swing() : BlockEventResponse("swing") {};

					/**
					* For some reason this is an empty object in the event json but eh
					*/
					void WriteToEventJson(rapidjson::Value* eventJson, rapidjson::MemoryPoolAllocator<>& allocator)
					{
						rapidjson::Value swingValue(rapidjson::kObjectType);
						eventJson->AddMember("swing", swingValue, allocator);
					}
				};
			}
		}
	}
}