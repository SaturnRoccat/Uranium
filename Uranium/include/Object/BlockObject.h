#pragma once
#include "CompilerObject.h"
#include <Utils/macros.h>
#include "ObjectComponents/ObjectComponents.h"
#include "ObjectComponents/BlockComponents/BlockComponent.h"
#include <string>

namespace Uranium
{
	namespace Creation
	{
		class BlockObject : public BaseObject<Components::BlockComponents::BlockComponent>
		{
		public:
			BlockObject(const char* name) : BaseObject(name) {}

			void getAsJsonData(rapidjson::Document* doc) override;
		private:
			void recursiveCompileComponents(rapidjson::Document* doc);
        };
	}
}