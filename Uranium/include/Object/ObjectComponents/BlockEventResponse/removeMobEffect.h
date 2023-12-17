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
				class RemoveMobEffect : public BlockEventResponse
				{
				private:
					std::string effect;
					std::string target;
				public:
					RemoveMobEffect(
						ConstStringRef effect,
						ConstStringRef target = "self"
					) : effect(effect), target(target), BlockEventResponse("play_sound") {}

					void WriteToEventJson(rapidjson::Value* eventJson, rapidjson::MemoryPoolAllocator<>& allocator) override
					{
						// play_effect object
						rapidjson::Value playEffectObject(rapidjson::kObjectType);
						// vars to object
						playEffectObject.AddMember("effect", RJ_STL_S(effect), allocator);
						SET_IF_NOT_DEFAULT_EX(
							target, "self", playEffectObject, allocator, "target", Utils::StrToRJ, .
						)
						// write to event json
						eventJson->AddMember("remove_mob_effect", playEffectObject, allocator);
					}
				};
			}
		}
	}
}