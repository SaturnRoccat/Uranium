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
				class playSound: public BlockEventResponse
				{
				private:
					std::string sound;
					std::string target;
				public:
					playSound(
						ConstStringRef sound,
						ConstStringRef target = "self"
					) : sound(sound), target(target), BlockEventResponse("play_sound") {}

					void WriteToEventJson(rapidjson::Value* eventJson, rapidjson::MemoryPoolAllocator<>& allocator) override
					{
						// play_effect object
						rapidjson::Value playEffectObject(rapidjson::kObjectType);
						// vars to object
						playEffectObject.AddMember("sound", RJ_STL_S(sound), allocator);
						SET_IF_NOT_DEFAULT_EX(
							target, "self", playEffectObject, allocator, "target", Utils::StrToRJ, .
						)
						// write to event json
						eventJson->AddMember("play_sound", playEffectObject, allocator);
					}
				};
			}
		}
	}
}