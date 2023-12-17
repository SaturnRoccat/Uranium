#include "Object/ObjectComponents/BlockComponents/selectionBox.h"
#include <Utils/macros.h>


namespace Uranium
{
    namespace Creation
    {
        namespace Components
        {
            namespace BlockComponents
            {
                /**
                * Just coped from /Uranium/src/Object/BlockComponent/collision_box.cpp
                */
                void SelectionBox::getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator)
                {
                    // Define all the values needed for the selection_box box
                    rapidjson::Value collisionBox(rapidjson::kObjectType);
                    rapidjson::Value origin(rapidjson::kArrayType);
                    rapidjson::Value size(rapidjson::kArrayType);

                    // Push back the origin
                    origin.PushBack(this->origin.x, allocator);
                    origin.PushBack(this->origin.y, allocator);
                    origin.PushBack(this->origin.z, allocator);

                    // Push back the size
                    size.PushBack(this->size.x, allocator);
                    size.PushBack(this->size.y, allocator);
                    size.PushBack(this->size.z, allocator);

                    // Add the values to the collision box
                    collisionBox.AddMember("origin", origin, allocator);
                    collisionBox.AddMember("size", size, allocator);

                    // Add the collision box to the write doc
                    writeDoc->AddMember("minecraft:selection_box", collisionBox, allocator);
                }
            }
        }
    }
}