#include <RPUtils/TextureUtilities/Texture/Texture.h>

#pragma warning(disable : 4267)
namespace Uranium
{
	namespace Creation
	{
		namespace TextureUtilities
		{
			void Texture::writeToDisk(const std::string& path)
			{
				if (this->m_layers.size() == 1) {
					m_layers[0].save(path.c_str());
				}
				else
				{
					Image finalImage = m_layers.back();
					for (int i = m_layers.size() - 2; i >= 0; --i) {
						alphaBlend(m_layers[i], finalImage);
					}
					finalImage.save(path.c_str()); 
				}
			}

			void Texture::alphaBlend(Image& top, Image& bottom)
			{
				cimg_forXY(top, x, y) {
					for (int c = 0; c < top.spectrum(); ++c) {
						bottom(x, y, c) =
							(top(x, y, c) * top(x, y, 3) + bottom(x, y, c) * (255 - top(x, y, 3))) / 255;
					}
				}
			}
			void Texture::colorMultiply(Image& top, Image& bottom)
			{
				cimg_forXY(top, x, y) {
					for (int c = 0; c < top.spectrum(); ++c) {
						bottom(x, y, c) =
							(top(x, y, c) * bottom(x, y, c)) / 255;
					}
				}
			}
			void Texture::colorAdd(Image& top, Image& bottom)
			{
				cimg_forXY(top, x, y) {
					for (int c = 0; c < top.spectrum(); ++c) {
						bottom(x, y, c) =
							(top(x, y, c) + bottom(x, y, c)) / 255;
					}
				}
			}
			void Texture::colorSubtract(Image& top, Image& bottom)
			{
				cimg_forXY(top, x, y) {
					for (int c = 0; c < top.spectrum(); ++c) {
						bottom(x, y, c) =
							(top(x, y, c) - bottom(x, y, c)) / 255;
					}
				}
			}
			void Texture::colorDivide(Image& top, Image& bottom)
			{
				cimg_forXY(top, x, y) {
					for (int c = 0; c < top.spectrum(); ++c) {
						bottom(x, y, c) =
							(top(x, y, c) / bottom(x, y, c)) / 255;
					}
				}
			}
		}
	}
}
