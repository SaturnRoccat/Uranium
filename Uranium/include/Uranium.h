#pragma once
#include "Registeries/ObjectRegistery.h"
#include "Object/CompilerObject.h"
#include "Object/BlockObject.h"
#include "UraniumGlobals.h"
#include <fstream>
namespace Uranium {
	/**
	* UraniumDK is the main class used by Uraniun. 
	* This class holds all the functions that you need to call to use Uranium.
	*/
	class UraniumDK {
	private:
	private:
	public:
		Creation::ObjectRegistry<Creation::BlockObject*> BlockRegistry;
	public:
		UraniumDK(const std::string& addonPrefix = "uranium_generated") {
			SetGlobalProjectNamespace(addonPrefix);
		}
		~UraniumDK()
		{
		}
		inline void RegisterBlock(Creation::BlockObject* block, std::string name = "")
		{
			if (name == "")
			{
				name = block->objectName;
			}
			BlockRegistry.registerDynamicObject(block, name);
		}
	public:
#ifdef EXPOSE_DEBUG_FUNCTIONS
		inline void DumpRegisteryToTempFolder(ConstStringRef path)
		{
			for (auto& block : this->BlockRegistry)
			{
				std::string filePath = path + block.first + ".json";
				std::ofstream file(filePath, std::ios::out );

				if (!file.is_open()) {
					Logs::Logger::Error("Could not open file: {}", filePath);
					continue;
				}

				rapidjson::Document doc;
				block.second->getAsJsonData(&doc);
				rapidjson::StringBuffer buffer;
				rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
				doc.Accept(writer);
				file << buffer.GetString();
				file.close();
			}
		}

#endif
	}; 
} // namespace Uranium