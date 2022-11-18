#include <SdlGraphics.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <Color.h>
#include <Rect.h>


static SDL_Window* window;
static SDL_Renderer* renderer;
static SDL_Texture* texture;

SdlGraphics::SdlGraphics() : hambourgeois::IGraphics()
{

}

SdlGraphics::~SdlGraphics()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
}

bool SdlGraphics::Initialize(const std::string& title, int w, int h)
{
	TTF_Init();
	int x = SDL_WINDOWPOS_CENTERED;
	int y = SDL_WINDOWPOS_CENTERED;

	uint32_t flags = SDL_WINDOW_TOOLTIP | SDL_WINDOW_RESIZABLE;
	window = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);

	if (!window)
	{
		//logger->Log(SDL_GetError());
		return false;
	}

	flags = SDL_RENDERER_ACCELERATED;
	renderer = SDL_CreateRenderer(window, -1, flags);
	if (!renderer)
	{
		//SDL_Log(SDL_GetError());
		return false;
	}

	return true;
}

void SdlGraphics::Shutdown()
{
	TTF_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void SdlGraphics::SetColor(const hambourgeois::Color& color)
{
	SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.alpha);
}

void SdlGraphics::Clear()
{
	SetColor(hambourgeois::Color::BLACK);
	SDL_RenderClear(renderer);
}

void SdlGraphics::Present()
{
	SDL_RenderPresent(renderer);
}

void SdlGraphics::DrawRect(float x, float y, float w, float h, const hambourgeois::Color& color)
{
	SDL_Rect sdlrect = { static_cast<int>(x), static_cast<int>(y),
		static_cast<int>(w), static_cast<int>(h) };
	SetColor(color);
	SDL_RenderDrawRect(renderer, &sdlrect);
}

void SdlGraphics::DrawRect(const hambourgeois::RectF& rect, const hambourgeois::Color& color)
{
	SDL_Rect sdlrect = { static_cast<int>(rect.x), static_cast<int>(rect.y),
		static_cast<int>(rect.w), static_cast<int>(rect.h) };
	SetColor(color);
	SDL_RenderDrawRect(renderer, &sdlrect);
}

void SdlGraphics::FillRect(float x, float y, float w, float h, const hambourgeois::Color& color)
{
	SDL_Rect sdlrect = { static_cast<int>(x), static_cast<int>(y),
		static_cast<int>(w), static_cast<int>(h) };
	SetColor(color);
	SDL_RenderFillRect(renderer, &sdlrect);
}

void SdlGraphics::FillRect(const hambourgeois::RectF& rect, const hambourgeois::Color& color)
{
	SDL_Rect sdlrect = { static_cast<int>(rect.x), static_cast<int>(rect.y),
		static_cast<int>(rect.w), static_cast<int>(rect.h) };
	SetColor(color);
	SDL_RenderFillRect(renderer, &sdlrect);
}

void SdlGraphics::DrawLine(float x1, float y1, float x2, float y2, const hambourgeois::Color& color)
{
	SetColor(color);
	SDL_RenderDrawLine(renderer, static_cast<int>(x1), static_cast<int>(y1),
		static_cast<int>(x2), static_cast<int>(y2));
}

size_t SdlGraphics::LoadTexture(const std::string& filename)
{
	const size_t textureId = std::hash<std::string>()(filename);
	if (textureCache.find(textureId) == textureCache.end()) // Doesn't exist in cache
	{
		textureCache[textureId] = IMG_LoadTexture(renderer, filename.c_str());
	}

	return textureId;
}

void SdlGraphics::DrawTexture(size_t id, const hambourgeois::RectI& src, const hambourgeois::RectF& dst, double angle, const hambourgeois::Flip& flip, const hambourgeois::Color& color)
{
	SDL_Rect initialRect = { static_cast<int>(src.x), static_cast<int>(src.y),
		static_cast<int>(src.w), static_cast<int>(src.h) };
	SDL_Rect destRect = { static_cast<int>(dst.x), static_cast<int>(dst.y),
		static_cast<int>(dst.w), static_cast<int>(dst.h) };

	SDL_RendererFlip rendererFlip = (SDL_RendererFlip)((int)flip.h | (int)flip.v << 1);
	SDL_SetTextureColorMod(textureCache[id], color.red, color.green, color.blue);
	SDL_SetTextureAlphaMod(textureCache[id], color.alpha);
	SDL_RenderCopyEx(renderer, textureCache[id], &initialRect, &destRect, angle, NULL, rendererFlip);
}

void SdlGraphics::DrawTexture(size_t id, const hambourgeois::RectF& dst, const hambourgeois::Color& color)
{
	SDL_Rect destRect = { static_cast<int>(dst.x), static_cast<int>(dst.y),
		static_cast<int>(dst.w), static_cast<int>(dst.h) };

	SDL_SetTextureColorMod(textureCache[id], color.red, color.green, color.blue);
	SDL_SetTextureAlphaMod(textureCache[id], color.alpha);
	SDL_RenderCopyEx(renderer, textureCache[id], NULL, &destRect, 0, NULL, SDL_FLIP_NONE);
}

void SdlGraphics::DrawTexture(size_t id, const hambourgeois::Color& color)
{
	SDL_SetTextureColorMod(textureCache[id], color.red, color.green, color.blue);
	SDL_SetTextureAlphaMod(textureCache[id], color.alpha);
	SDL_RenderCopyEx(renderer, textureCache[id], NULL, NULL, 0, NULL, SDL_FLIP_NONE);
}

void SdlGraphics::GetTextureSize(size_t id, int* w, int* h)
{
	if (textureCache.count(id) > 0)
	{
		SDL_Texture* _tex = textureCache[id];
		SDL_QueryTexture(_tex, nullptr, nullptr, w, h);
	}
	else
	{
		*w = 0;
		*h = 0;
	}
}

size_t SdlGraphics::LoadFont(const std::string& filename, int fontSize)
{
	const size_t fontId = std::hash<std::string>()(filename);
	if (fontCache.find(fontId) == fontCache.end()) // Doesn't exist in cache
	{
		fontCache[fontId] = TTF_OpenFont(filename.c_str(), fontSize);
	}

	return fontId;
}

void SdlGraphics::DrawString(const std::string& text, size_t fontId, float x, float y, const hambourgeois::Color& color)
{
	if (fontCache.count(fontId) > 0)
	{
		TTF_Font* font = fontCache[fontId];
		SDL_Color c = { color.red, color.green, color.blue, color.alpha };
		SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), c);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_Rect dst = { static_cast<int>(x), static_cast<int>(y),
			static_cast<int>(surface->w), static_cast<int>(surface->h) };

		SDL_RenderCopy(renderer, texture, nullptr, &dst);
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
	}
}

void SdlGraphics::GetTextSize(const std::string& text, size_t fontId, int* w, int* h)
{
	TTF_SizeText(fontCache[fontId], text.c_str(), w, h);
}

void SdlGraphics::GetWindowSize(int* w, int* h)
{
	SDL_GetWindowSize(window, w, h);
}

void SdlGraphics::LoadTileset(const std::string& filename, int tileW, int tileH, int col, int count)
{
	const size_t textureId = std::hash<std::string>()(filename);
	if (tilesetCache.find(textureId) != tilesetCache.end())
	{
		texture = tilesetCache[textureId];
	}
	else
	{
		texture = IMG_LoadTexture(renderer, filename.c_str());
		tilesetCache[textureId] = texture;

		if (texture)
		{
			for (int i = 0; i < count; i++)
			{
				int y = i / col;
				int x = i - y * col;
				hambourgeois::RectI tile
				{
					x * tileW,
					y * tileH,
					tileW,
					tileH 
				};

				tileset.push_back(tile);
			}
		}
	}
}

void SdlGraphics::DrawTiles(int tileW, int tileH, size_t tileset)
{
	TTileset tlset = tilesetRectCache[tileset];
	for (auto layer : tilemap)
	{
		for (int y = 0; y < layer.second.size(); y++)
		{
			for (int x = 0; x < layer.second[y].size(); x++)
			{
				int _index = layer.second[y][x] - 1;
				if (_index >= 0)
				{
					SDL_Rect _src{
						tlset[_index].x,
						tlset[_index].y,
						tlset[_index].w,
						tlset[_index].h
					};
					SDL_Rect _dst{
						x * tileW,
						y * tileH,
						tileW,
						tileH };

					SDL_RenderCopyEx(renderer, tilesetCache[tileset],
						&_src, &_dst, 0.0, nullptr, SDL_FLIP_NONE);
				}
			}
		}
	}
}