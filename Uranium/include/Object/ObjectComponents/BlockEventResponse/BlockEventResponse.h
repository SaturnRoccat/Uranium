#pragma once
#include "../../EventResponse.h"

namespace Uranium
{
	namespace Creation
	{
		namespace Events
		{
			namespace BlockEvent
			{
				/**
				* This class is more of just an interface for the EventResponse class
				*/
				class BlockEventResponse : public Events::EventResponse
				{
				public:
					BlockEventResponse(ConstStringRef name) : Events::EventResponse(name) {}

					virtual void WriteToEventJson(rapidjson::Value* eventJson, rapidjson::MemoryPoolAllocator<>& allocator) = 0;
				};
			}
		}
	}
}