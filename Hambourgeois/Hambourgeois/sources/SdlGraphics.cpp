//#include "../includes/SdlGraphics.h"
#include <SdlGraphics.h>
#include <SDL.h>
#include <SDL_image.h>
#include <Color.h>
#include <Rect.h>

SdlGraphics::~SdlGraphics()
{
}

SdlGraphics::SdlGraphics() : hambourgeois::IGraphics()
{
}

bool SdlGraphics::Initialize(const std::string& title, int w, int h)
{
	int x = SDL_WINDOWPOS_CENTERED;
	int y = SDL_WINDOWPOS_CENTERED;

	uint32_t flags = SDL_WINDOW_TOOLTIP | SDL_WINDOW_RESIZABLE;
	window = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);

	if (window != nullptr)
	{
		//hambourgeois::Engine::Logger
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
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void SdlGraphics::SetColor(const hambourgeois::Color& color)
{
	SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.alpha);
}

void SdlGraphics::Clear()
{
	SDL_RenderClear(renderer);
}

void SdlGraphics::Present()
{
	SDL_RenderPresent(renderer);
}

void SdlGraphics::DrawRect(float x, float y, float w, float h, const hambourgeois::Color& color)
{
}

void SdlGraphics::DrawRect(const hambourgeois::RectF& rect, const hambourgeois::Color& color)
{
}

void SdlGraphics::FillRect(float x, float y, float w, float h, const hambourgeois::Color& color)
{
}

void SdlGraphics::FillRect(const hambourgeois::RectF& rect, const hambourgeois::Color& color)
{
}

void SdlGraphics::DrawLine(float x1, float y1, float x2, float y2, const hambourgeois::Color& color)
{
}

size_t SdlGraphics::LoadTexture(const std::string& filename)
{
	return size_t();
}

/*void SdlGraphics::DrawTexture(size_t id, const hambourgeois::RectI& src, const hambourgeois::RectF& dst, double angle, const Flip& flip, const hambourgeois::Color& color)
{
}*/

void SdlGraphics::DrawTexture(size_t id, const hambourgeois::RectF& dst, const hambourgeois::Color& color)
{
}

void SdlGraphics::DrawTexture(size_t id, const hambourgeois::Color& color)
{
}

void SdlGraphics::GetTextureSize(size_t id, int* w, int* h)
{
}

size_t SdlGraphics::LoadFont(const std::string& filename, int fontSize)
{
	return size_t();
}

void SdlGraphics::DrawString(const std::string& text, size_t fontId, float x, float y, const hambourgeois::Color& color)
{
}

void SdlGraphics::GetTextSize(const std::string& text, size_t fontId, int* w, int* h)
{
}
