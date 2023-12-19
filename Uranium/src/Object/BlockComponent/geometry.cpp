#include <Object/ObjectComponents/BlockComponents/geometry.h>

void Uranium::Creation::Components::BlockComponents::Geometry::getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator)
{
    rapidjson::Value geo(RJ_STL_S(this->name));
    writeDoc->AddMember("minecraft:geometry", geo, allocator);
}
