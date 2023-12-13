#pragma once
#include "CompilerObject.h"
#include <Utils/macros.h>
#include <string>

namespace Uranium
{
	namespace Creation
	{
		class BlockObject : public BaseObject<BlockObject>
		{
		public:
			BlockObject(const char* name) : BaseObject(name) {}
        };
	}
}