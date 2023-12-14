#pragma once
#include "BlockComponent.h"

namespace Uranium
{
	namespace Creation
	{
		namespace Components
		{
			namespace BlockComponents
			{
				class DisplayName : public BlockComponent
				{
				private:
					std::string name;
				public:
					DisplayName(const std::string& name = "Custom Display name!!!!!") : name(name), BlockComponent("display_name") {}

					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override;
				};
			}
		}
	}
}