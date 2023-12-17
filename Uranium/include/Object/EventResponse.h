#pragma once
#include "../Utils/RapidProxy.h"
#include "../Utils/RandomTypes.h"
#include "../Utils/macros.h"
#include <string>
namespace Uranium
{
	namespace Creation
	{
		namespace Events
		{
			class EventResponse
			{
			private:
			public:
				EventResponse(ConstStringRef name) : name(name) {}
				virtual void WriteToEventJson(rapidjson::Value* eventJson, rapidjson::MemoryPoolAllocator<>& allocator) = 0;
			public:
				std::string name;
			};
		}
	}
}