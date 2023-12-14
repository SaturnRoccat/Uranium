#pragma once
#include <Object/ObjectComponents/BlockComponents/BlockComponent.h>

namespace Uranium
{
	namespace Creation
	{
		namespace Components
		{
			namespace BlockComponents
			{
				class CraftingTable : public BlockComponent
				{
				private:
					std::vector<std::string> crafting_tags;
					std::string table_name;
				public:
					CraftingTable(const std::vector<std::string>& crafting_tags = {"minecraft:crafting_table"}, const std::string& table_name = "table") : BlockComponent("crafting_table"), crafting_tags(crafting_tags), table_name(table_name) {}

					void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) override;
				};
			}
		}
	}
}