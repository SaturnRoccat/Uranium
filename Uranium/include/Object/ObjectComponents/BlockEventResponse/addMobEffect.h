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
				class AddMobEffect : public BlockEventResponse
				{
				private:
					int amplifier;
					double duration;
					std::string effect;
					std::string target;
				public:
					AddMobEffect(
						ConstStringRef effect,
						int amplifier = 0,
						double duration = 0.0,
						ConstStringRef target = "self"
					) : effect(effect), amplifier(amplifier), duration(duration), target(target), BlockEventResponse("add_mob_effect") {}

					void WriteToEventJson(rapidjson::Value* eventJson, rapidjson::MemoryPoolAllocator<>& allocator) override 
					{
						// Create the add_mob_effect object
						rapidjson::Value addMobEffect(rapidjson::kObjectType);
						addMobEffect.AddMember("effect", RJ_STL_S(effect), allocator);

						SET_IF_NOT_DEFAULT(
							amplifier,
							0,
							addMobEffect,
							allocator,
							"amplifier",
							.)
						SET_IF_NOT_DEFAULT(
							duration,
							0.0,
							addMobEffect,
							allocator,
							"duration",
							.)
						SET_IF_NOT_DEFAULT_EX(
							target,
							"self",
							addMobEffect,
							allocator,
							"target",
							Utils::StrToRJ,
							.
						)

						// Add the add_mob_effect object to the event object
						eventJson->AddMember("add_mob_effect", addMobEffect, allocator);

					}
					
				};
			}
		}
	}
}