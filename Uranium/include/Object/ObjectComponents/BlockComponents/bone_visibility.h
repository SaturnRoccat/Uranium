#pragma once
#include "BlockComponent.h"
#include <tuple>
#include <string>

namespace Uranium
{
	namespace Creation
	{
		namespace Components
		{
			namespace BlockComponents
			{
				/**
				* This is just the ObjectCmponent but with a different name for the sake of clarity
				*/
				class bone_visibility : public BlockComponent
				{
				private:
					std::vector<std::pair<std::string, std::string>> bonePairVisiblity;
				public:
					bone_visibility(const std::vector<std::pair<std::string, std::string>>& bonePairVisiblity) : bonePairVisiblity(bonePairVisiblity), BlockComponent("bone_visibility", {Experiments::HolidayCreatorFeatures}, true) {}
					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override;
				};
			}
		}
	}
}