#include <SdlServiceProvider.h>
#include <SDL.h>

SdlServiceProvider::SdlServiceProvider() : hambourgeois::IServiceProvider()
{
}

SdlServiceProvider::~SdlServiceProvider()
{
	Quit();
}

bool SdlServiceProvider::Initialize()
{
	return SDL_Init(SDL_INIT_EVERYTHING) == 0;
}

bool SdlServiceProvider::Quit()
{
	SDL_Quit();
	return true;
}
