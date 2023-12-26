#pragma once
#include <string>
#include <Utils/RapidProxy.h>
namespace Uranium
{
	namespace Creation
	{
		namespace Events
		{
			class Event
			{
			public:
				Event(const std::string& name) : name(name) {}
				virtual void WriteToEventJson(rapidjson::Value* eventJson, rapidjson::MemoryPoolAllocator<>& allocator) = 0;
			public:
				std::string name;
			};
		}
	}
}