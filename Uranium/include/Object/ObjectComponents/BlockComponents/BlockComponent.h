#pragma once
#include "../ObjectComponents.h"
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
				* This is just the ObjectComponent but with a different name for the sake of clarity
				*/
				class BlockComponent : public ObjectComponent
				{
				public:
					BlockComponent(const char* name, std::vector<Experiments> requiredExperiments = { Experiments::None }, bool skipInCompilation = false) : ObjectComponent(name, requiredExperiments, skipInCompilation) {}
					virtual void getAsJsonData(rapidjson::Value* writeDoc, rapidjson::MemoryPoolAllocator<>& allocator) = 0;// Never Ever call this function
				};
			}
		}
	}
}