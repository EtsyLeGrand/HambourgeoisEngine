#include <SdlGraphics.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <Color.h>
#include <Rect.h>


static SDL_Window* window;
static SDL_Renderer* renderer;

SdlGraphics::SdlGraphics() : hambourgeois::IGraphics()
{

}

SdlGraphics::~SdlGraphics()
{
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
	SDL_Rect sdlrect = { x, y, w, h };
	SetColor(color);
	SDL_RenderDrawRect(renderer, &sdlrect);
}

void SdlGraphics::DrawRect(const hambourgeois::RectF& rect, const hambourgeois::Color& color)
{
	SDL_Rect sdlrect = { rect.x, rect.y, rect.w, rect.h };
	SetColor(color);
	SDL_RenderDrawRect(renderer, &sdlrect);
}

void SdlGraphics::FillRect(float x, float y, float w, float h, const hambourgeois::Color& color)
{
	SDL_Rect sdlrect = { x, y, w, h };
	SetColor(color);
	SDL_RenderFillRect(renderer, &sdlrect);
}

void SdlGraphics::FillRect(const hambourgeois::RectF& rect, const hambourgeois::Color& color)
{
	SDL_Rect sdlrect = { rect.x, rect.y, rect.w, rect.h };
	SetColor(color);
	SDL_RenderFillRect(renderer, &sdlrect);
}

void SdlGraphics::DrawLine(float x1, float y1, float x2, float y2, const hambourgeois::Color& color)
{
	SetColor(color);
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
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
	SDL_Rect initialRect = { src.x, src.y, src.w, src.h };
	SDL_Rect destRect = { dst.x, dst.y, dst.w, dst.h };
	SDL_RendererFlip rendererFlip = (SDL_RendererFlip)((int)flip.h | (int)flip.v << 1);
	SDL_SetTextureColorMod(textureCache[id], color.red, color.green, color.blue);
	SDL_SetTextureAlphaMod(textureCache[id], color.alpha);
	SDL_RenderCopyEx(renderer, textureCache[id], &initialRect, &destRect, angle, NULL, rendererFlip);
}

void SdlGraphics::DrawTexture(size_t id, const hambourgeois::RectF& dst, const hambourgeois::Color& color)
{
	SDL_Rect destRect = { dst.x, dst.y, dst.h, dst.w };
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
		SDL_Rect dst = { x, y, surface->w, surface->h };

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