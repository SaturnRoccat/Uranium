#include <Object/ObjectComponents/BlockComponents/boxBreathability.h>
#include <Utils/macros.h>

#if URANIUM_TARGET_FORMAT_VERSION <= 11941
namespace Uranium
{
    namespace Creation
    {
        namespace Components
        {
            namespace BlockComponents
            {
                void box_breathability::getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator)
                {
                    // Just need to add a component which looks like "minecraft:breathability": then our val 
                    // Just push the value to the document
                    rapidjson::Value breathabilityKey; // Create a JSON string for the key
                    breathabilityKey.SetString("minecraft:breathability");

                    rapidjson::Value breathabilityValue; // Create a JSON string value
                    std::string& val = this->val;
                    breathabilityValue.SetString(RJ_STL_S(val));

                    writeDoc->AddMember(breathabilityKey, breathabilityValue, allocator);
                }


            }
        }
    }
}
#endif



