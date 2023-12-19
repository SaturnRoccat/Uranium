#include "Object/ObjectComponents/BlockComponents/boneVisibility.h"
#include <Utils/macros.h>


namespace Uranium
{
	namespace Creation
	{
        namespace Components
        {
            namespace BlockComponents
            {
                void bone_visibility::getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator)
                {
                    // We are going to assume that writeDoc is the components json and not the base json

                    // In this case we just need to push back a "bone_visibility" and have an object with strings and string pairs

                    //create the object that we are going to push back
                    rapidjson::Value boneVisibilityObject(rapidjson::kObjectType);
                    // Add the strings and string pairs
                    for (auto& stringPair : this->bonePairVisiblity)
                    {
                        // Create rapidjson::Value for the keys and values
                        rapidjson::Value key(RJ_STL_S(stringPair.first));
                        rapidjson::Value value(RJ_STL_S(stringPair.second));

                        // Add the string pair
                        boneVisibilityObject.AddMember(key, value, allocator);
                    }
                    // Add the object to the writeDoc
                    rapidjson::Value visibilityKey("bone_visibility", allocator);
                    writeDoc->AddMember(visibilityKey, boneVisibilityObject, allocator);
                }
            }
        }
	}
}