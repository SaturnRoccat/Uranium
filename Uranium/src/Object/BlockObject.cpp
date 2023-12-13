#include <Object/BlockObject.h>
#include <UraniumGlobals.h>
#include <Utils/UtilFunctions.h>

namespace Uranium
{
	namespace Creation
	{
        rapidjson::Document BlockObject::GetAsJson() {
            rapidjson::Document returnDoc;
            returnDoc.SetObject();
            rapidjson::Document::AllocatorType& allocator = returnDoc.GetAllocator();

            // add the format version directly without creating a separate string variable
            returnDoc.AddMember("formatVersion", GlobalBlockFormatVersion.toString(), allocator);

            // add the minecraft::block object
            rapidjson::Value blockObject(rapidjson::kObjectType);

            // add the description object directly to the blockObject
            blockObject.AddMember("description", rapidjson::Value(rapidjson::kObjectType), allocator);

            // Get a reference to the "description" object within the blockObject
            rapidjson::Value& descriptionObject = blockObject["description"];

            // add the identifier directly to the descriptionObject without creating a separate object
            descriptionObject.AddMember("identifier", Utils::GetNameWithNamespace(this->objectName), allocator);

            // add the menu_catagory object directly to the descriptionObject
            descriptionObject.AddMember("menu_catagory", rapidjson::Value(rapidjson::kObjectType), allocator);

            // add the components object directly to the blockObject
            blockObject.AddMember("components", rapidjson::Value(rapidjson::kObjectType), allocator);

            // add the block object to the document
            returnDoc.AddMember("minecraft:block", blockObject, allocator);

            // compile the components
            this->recursiveCompileComponents(&returnDoc);

            //TODO: add events
            //TODO: add permutations

            return returnDoc; // Move semantics will prevent unnecessary copying
        }

        void BlockObject::recursiveCompileComponents(rapidjson::Document* doc) {
			// Get a reference to the "components" object within the blockObject
			rapidjson::Value& componentsObject = (*doc)["minecraft:block"]["components"];

            // Loop through all of the components in the objectRegistery
            for (auto comp : this->objectRegistery) {
				// Get the component as a rapidjson::Document
                rapidjson::Value componentAsJson = (*comp.second)->getAsJsonData().jsonRepresentation;

				// Get the name of the component
                std::string componentName = (*comp.second)->componentName;

				// Add the component to the componentsObject
				componentsObject.AddMember(rapidjson::Value(componentName.c_str(), componentName.size(), doc->GetAllocator()), componentAsJson, doc->GetAllocator());
			}
		}

	}
}