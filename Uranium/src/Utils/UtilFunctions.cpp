#include "Utils/UtilFunctions.h"
#include "UraniumGlobals.h"
#include <UUID_V4/UUID_V4.h>

namespace Uranium
{
	namespace Utils
	{
		std::string GetNameWithNamespace(std::string& name)
		{
			return Uranium::GlobalProjectNamespace + ":" + name;
		}


		std::string CreateUUID()
		{
			return std::string(Uranium::GlobalUUIDGenerator.getUUID().str());
		}
	}
}