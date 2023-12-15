#pragma once
#include <string>
#include "Utils/RandomTypes.h"

namespace Uranium
{
	namespace Creation
	{
		namespace Components
		{
			namespace BlockComponents
			{
				namespace SubClasses
				{
					class materialInstanceSegment
					{
					public:
						bool ambientOcclusion = false;
						bool faceDimming = true;
						std::string renderMethod = "opaque";
						std::string texture = "";
						std::string target = "*";
					public:
						materialInstanceSegment(
							ConstStringRef texture,
							ConstStringRef target = "*",
							bool ambientOcclusion = false,
							bool faceDimming = true,
							ConstStringRef renderMethod = "opaque"
						) : texture(texture), target(target), ambientOcclusion(ambientOcclusion), faceDimming(faceDimming), renderMethod(renderMethod) {}
					private:
					};
				}
			}
		}
	}
}