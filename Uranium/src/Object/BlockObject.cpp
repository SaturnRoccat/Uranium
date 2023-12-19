#include <Object/BlockObject.h>
#include <UraniumGlobals.h>
#include <Utils/UtilFunctions.h>
#include <Utils/macros.h>



namespace Uranium
{
	namespace Creation
	{
        void BlockObject::getAsJsonData(rapidjson::Document* doc) {
            doc->SetObject();
            rapidjson::Document::AllocatorType& allocator = doc->GetAllocator();

            // add the format version directly without creating a separate string variable
            // Convert the version number to a c_str
            std::string version = Uranium::GlobalFormatVersion.toString();
            doc->AddMember("format_version", RJ_STL_S(version), allocator);

            // add the minecraft::block object
            rapidjson::Value blockObject(rapidjson::kObjectType);

            // add the description object directly to the blockObject
            blockObject.AddMember("description", rapidjson::Value(rapidjson::kObjectType), allocator);

            // Get a reference to the "description" object within the blockObject
            rapidjson::Value& descriptionObject = blockObject["description"];

            // add the identifier directly to the descriptionObject without creating a separate object
            std::string identifier = Utils::GetNameWithNamespace(this->objectName);
            descriptionObject.AddMember("identifier", RJ_STL_S(identifier), allocator);

            // add the menu_catagory object directly to the descriptionObject
            descriptionObject.AddMember("menu_catagory", rapidjson::Value(rapidjson::kObjectType), allocator);

            // add the components object directly to the blockObject
            blockObject.AddMember("components", rapidjson::Value(rapidjson::kObjectType), allocator);

            // add the block object to the document
            doc->AddMember("minecraft:block", blockObject, allocator);

            // compile the components
            this->recursiveCompileComponents(doc);

            //TODO: add events
            //TODO: add permutations
            DEBUG_CODE(
                rapidjson::StringBuffer buffer;
                rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
                doc->Accept(writer);
                Logs::Logger::Info(buffer.GetString());
            )
        }

        void BlockObject::recursiveCompileComponents(rapidjson::Document* doc) {
			// Get a reference to the "components" object within the blockObject
			rapidjson::Value& componentsObject = (*doc)["minecraft:block"]["components"];
            // Get an allocator ref from the document
            rapidjson::Document::AllocatorType& allocator = doc->GetAllocator();

            // Loop through all of the components in the objectRegistery
            for (auto comp : this->objectRegistery) {
                if (comp.second->skipInCompiliation)
                    continue; // skip the component if it is marked to be skipped
                // Call the getAsJsonData function on the component to add it to the componentsObject
                (*(comp.second)).getAsJsonData(&componentsObject, allocator);
			}
		}

	}
}