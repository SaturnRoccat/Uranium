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
				class playEffect : public BlockEventResponse
				{
				private:
					int data;
					std::string effect;
					std::string target;
				public:
					playEffect(
						ConstStringRef effect,
						ConstStringRef target = "self",
						int data = 0
					) : effect(effect), target(target), data(data), BlockEventResponse("play_effect") {}
				
					void WriteToEventJson(rapidjson::Value* eventJson, rapidjson::MemoryPoolAllocator<>& allocator) override 
					{
						// play_effect object
						rapidjson::Value playEffectObject(rapidjson::kObjectType);
						// vars to object
						playEffectObject.AddMember("effect", RJ_STL_S(effect), allocator);
						SET_IF_NOT_DEFAULT_EX(
							target, "self", playEffectObject, allocator, "target", Utils::StrToRJ, . 
						)
						SET_IF_NOT_DEFAULT(
							data,
							0,
						playEffectObject,
						allocator,
						"data",
						.
						)
						// write to event json
						eventJson->AddMember("play_effect", playEffectObject, allocator);
					}
				};
			}
		}
	}
}