#pragma once
#include "Cimg/CimgProxy.h"
#include <vector>
#include <string>

namespace Uranium
{
	namespace Creation 
	{
		namespace TextureUtilities
		{
			struct Color
			{
				unsigned char r;
				unsigned char g;
				unsigned char b;
				unsigned char a;
			};

			enum class DefaultState
			{
				_TRANSPARENT,
				SOLID,
			};
			class Texture
			{
			public:
				Texture(int Size, DefaultState Ds = DefaultState::_TRANSPARENT) : m_size(Size), m_defaultState(Ds) {
					Image defaultLayer(Size, Size, 1, 4); // 3 Channels
					if (m_defaultState == DefaultState::_TRANSPARENT)
						defaultLayer.fill(0);
					else
						defaultLayer.fill(255);
					m_layers.push_back(defaultLayer);
				}
				/**
				* All layers get added to the bottom of the stack
				*/
				inline void addLayer() {
					Image newLayer(m_size, m_size, 1, 4);
					if (m_defaultState == DefaultState::_TRANSPARENT)
						newLayer.fill(0);
					else
						newLayer.fill(255);
					m_layers.push_back(newLayer);
				}

				inline void addLayer(Image& layer) {
					m_layers.push_back(layer);
				}

				void writeToDisk(const std::string& path);

				void alphaBlend(Image& top, Image& bottom);
				void colorMultiply(Image& top, Image& bottom);
				void colorAdd(Image& top, Image& bottom);
				void colorSubtract(Image& top, Image& bottom);
				void colorDivide(Image& top, Image& bottom);
				

				inline void setPixel(Color col = { 255, 255, 255 ,255 }, int x = 0, int y = 0, int layer = 0) {
					m_layers[layer](x, y, 0, 0) = col.r;
					m_layers[layer](x, y, 0, 1) = col.g;
					m_layers[layer](x, y, 0, 2) = col.b;
					m_layers[layer](x, y, 0, 3) = col.a;
				}

				inline void drawCircle(Color col = { 255, 255, 255, 255 }, int x0 = 0, int y0 = 0, int radius = 16, int layer = 0)
				{
					int x = radius;
					int y = 0;
					int err = 0;

					while (x >= y)
					{
						setPixel(col, x0 + x, y0 + y, layer);
						setPixel(col, x0 + y, y0 + x, layer);
						setPixel(col, x0 - y, y0 + x, layer);
						setPixel(col, x0 - x, y0 + y, layer);
						setPixel(col, x0 - x, y0 - y, layer);
						setPixel(col, x0 - y, y0 - x, layer);
						setPixel(col, x0 + y, y0 - x, layer);
						setPixel(col, x0 + x, y0 - y, layer);

						if (err <= 0)
						{
							y += 1;
							err += 2 * y + 1;
						}
						if (err > 0)
						{
							x -= 1;
							err -= 2 * x + 1;
						}
					}
				}
				inline void drawLine(Color col = { 255, 255, 255, 255 }, int x0 = 0, int y0 = 0, int x1 = 0, int y1 = 0, int layer = 0)
				{
					int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
					int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
					int err = (dx > dy ? dx : -dy) / 2, e2;

					for (;;) {
						setPixel(col, x0, y0, layer);
						if (x0 == x1 && y0 == y1) break;
						e2 = err;
						if (e2 > -dx) { err -= dy; x0 += sx; }
						if (e2 < dy) { err += dx; y0 += sy; }
					}
				}
				inline void drawRectangle(Color col = { 255, 255, 255, 255 }, int x = 0, int y = 0, int width = 16, int height = 16, int layer = 0) {
					for (int x1 = x; x1 < x + width; x1++) {
						for (int y1 = y; y1 < y + height; y1++) {
							setPixel(col, x1, y1, layer);
						}
					}
				}
			private:
				std::vector<Image> m_layers;
				const int m_size;
				DefaultState m_defaultState;
			};
		}
	}
}