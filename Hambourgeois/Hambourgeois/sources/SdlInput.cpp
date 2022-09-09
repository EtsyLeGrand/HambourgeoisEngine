#include <SdlInput.h>
#include <SDL.h>

SdlInput::SdlInput()
{
}

void SdlInput::Update()
{
	SDL_Event inputEvent;
	while (SDL_PollEvent(&inputEvent))
	{
		switch (inputEvent.type)
		{
		case SDL_QUIT:
#if _DEBUG
			hambourgeois::Engine::Exit();
#endif
			break;
		case SDL_MOUSEBUTTONDOWN:
			SDL_MouseButtonEvent buttonDown = inputEvent.button;
			SDL_Log("Button down : %d", buttonDown.button);
			SDL_Log("at (%d, %d)", buttonDown.x, buttonDown.y);
			break;
		case SDL_MOUSEBUTTONUP:
			SDL_MouseButtonEvent buttonUp = inputEvent.button;
			break;
		case SDL_KEYDOWN:
			keyStates = SDL_GetKeyboardState(nullptr);
			break;
		case SDL_KEYUP:
			keyStates = SDL_GetKeyboardState(nullptr);
			break;
		}
	}
}

bool SdlInput::IsKeyDown(int key)
{
	if (keyStates == nullptr) return false;
	return keyStates[key];
}

bool SdlInput::IsButtonDown(int button)
{
	return false;
}

void SdlInput::GetMousePosition(int* x, int* y)
{
}
