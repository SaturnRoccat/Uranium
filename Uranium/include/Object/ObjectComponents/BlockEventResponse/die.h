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
				class die : public BlockEventResponse
				{
				private:
					std::string target;
				public:
					die(ConstStringRef target = "self") : target(target), BlockEventResponse("die") {}

					void WriteToEventJson(rapidjson::Value* eventJson, rapidjson::MemoryPoolAllocator<>& allocator) override
					{
						// Make the Die object
						rapidjson::Value dieObject(rapidjson::kObjectType);
						// Add the target
						dieObject.AddMember("target", rapidjson::StringRef(target.c_str()), allocator);
						// Add the Die object to the event
						eventJson->AddMember("die", dieObject, allocator);
					}
				};
			}
		}
	}
}