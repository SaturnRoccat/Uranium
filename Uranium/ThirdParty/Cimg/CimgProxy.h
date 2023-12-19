#pragma once
// #define cimg_use_png // Enable PNG support
// Silences the barrage of warnings from CImg
#pragma warning (disable: 26819)
#pragma warning (disable: 28182)
#pragma warning (disable: 6011)
#pragma warning (disable: 6258)
#pragma warning (disable: 6835)
#pragma warning (disable: 6262)
#pragma warning (disable: 6031)
#pragma warning (disable: 6385)
#pragma warning (disable: 6387)
#include "CImg.h"
namespace CI = cimg_library;
typedef CI::CImg<unsigned char> Image;
#pragma warning (default: 26819)
#pragma warning (default: 28182)
#pragma warning (default: 6011)
#pragma warning (default: 6258)
#pragma warning (default: 6387)
#pragma warning (default: 6835)
#pragma warning (default: 6262)
#pragma warning (default: 6031)
#pragma warning (default: 6385)
