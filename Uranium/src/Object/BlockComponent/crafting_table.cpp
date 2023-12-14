#include <Object/ObjectComponents/BlockComponents/crafting_table.h>
namespace Uranium
{
    namespace Creation
    {
        namespace Components
        {
            namespace BlockComponents
            {
                void CraftingTable::getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator)
                {
                    rapidjson::Value craftingTable(rapidjson::kObjectType);
                    RJ_STL_V_A_EX(crafting_tags, this->crafting_tags, allocator, Utils::StrToRJ);
                    auto tableName = RJ_STL_S(this->table_name);
                    craftingTable.AddMember("crafting_tags", crafting_tags, allocator);
                    craftingTable.AddMember("table_name", tableName, allocator);
                    writeDoc->AddMember("minecraft:crafting_table", craftingTable, allocator);

                }
            }
        }
    }
}