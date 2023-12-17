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
				class damage : public BlockEventResponse
				{
				private:
					int amount;
					int mobAmount;
					std::string target;
					std::string type;
				public:
					damage(
						ConstStringRef type,
						ConstStringRef target = "self",
						int amount = 0,
						int mobAmount = 0
					) : type(type), target(target), amount(amount), mobAmount(mobAmount), BlockEventResponse("damage") {}

					void WriteToEventJson(rapidjson::Value* eventJson, rapidjson::MemoryPoolAllocator<>& allocator) override
					{
						// create the damage object
						rapidjson::Value damage(rapidjson::kObjectType);
						damage.AddMember("type", RJ_STL_S(type), allocator);
						SET_IF_NOT_DEFAULT_EX(
                             target,
							"self",
							damage,
							allocator,
							"target",
							Utils::StrToRJ,
							.
						)
						SET_IF_NOT_DEFAULT(
							amount,
							0,
							damage,
							allocator,
							"amount",
						    .
						)

						SET_IF_NOT_DEFAULT(
							mobAmount,
							0,
							damage,
							allocator,
							"mob_amount",
							.
						)

						// add the damage object to the event json
						eventJson->AddMember("damage", damage, allocator);
					}

				};
			}
		}
	}
}