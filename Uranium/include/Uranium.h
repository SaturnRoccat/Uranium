#pragma once
#include "Registeries/ObjectRegistery.h"
#include "Object/CompilerObject.h"
#include "Object/BlockObject.h"
#include "UraniumGlobals.h"

namespace Uranium {
	/**
	* UraniumDK is the main class used by Uraniun. 
	* This class holds all the functions that you need to call to use Uranium.
	*/
	class UraniumDK {
	private:
	private:
	public:
		Creation::ObjectRegistery<Creation::BlockObject> BlockRegistery;
	public:
		UraniumDK(const std::string& addonPrefix = "uranium_generated") {
			SetGlobalProjectNamespace(addonPrefix);
		}
	}; 
} // namespace Uranium