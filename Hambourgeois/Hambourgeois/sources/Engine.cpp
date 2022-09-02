#include <Engine.h>
#include <SDL.h>
#include <time.h>
#include <Windows.h>

static SDL_Renderer* _renderer = nullptr;
static SDL_Window* _window = nullptr;
static unsigned char const* _keys = nullptr;

#define TARGET_FPS 60.0

static float const MS_PER_FRAME = 1000 / TARGET_FPS;

static float xPos = 0;
static float yPos = 0;

bool hambourgeois::Engine::Init(const std::string& title, int w, int h)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_Log(SDL_GetError());
		return false;
	}

	int x = SDL_WINDOWPOS_CENTERED;
	int y = SDL_WINDOWPOS_CENTERED;

	uint32_t flags = SDL_WINDOW_TOOLTIP | SDL_WINDOW_RESIZABLE;
	_window = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);

	if (!_window)
	{
		SDL_Log(SDL_GetError());
		return false;
	}

	flags = SDL_RENDERER_ACCELERATED;
	_renderer = SDL_CreateRenderer(_window, -1, flags);

	if (!_renderer)
	{
		SDL_Log(SDL_GetError());
		return false;
	}


	return true;
}

void hambourgeois::Engine::Start()
{
	isRunning = true;
	clock_t lastTime = clock();
	float lag = 0.0f;
	while (isRunning)
	{
		const clock_t start = clock();
		float dt = (start - lastTime) * 0.001f;

		lag += dt;

		ProcessInput();
		Update(dt);
		Render();

		Sleep(MS_PER_FRAME - dt);

		lastTime = start;
	}

	Shutdown();
}

void hambourgeois::Engine::Exit()
{
	isRunning = false;
}

void hambourgeois::Engine::ProcessInput()
{
	SDL_Event inputEvent;
	while (SDL_PollEvent(&inputEvent))
	{
		switch (inputEvent.type)
		{
		case SDL_QUIT:
			Exit();
			break;
		case SDL_MOUSEBUTTONDOWN:
			SDL_MouseButtonEvent buttonDown = inputEvent.button;
			break;
		case SDL_MOUSEBUTTONUP:
			SDL_MouseButtonEvent buttonUp = inputEvent.button;
			break;
		case SDL_KEYDOWN:
			_keys = SDL_GetKeyboardState(nullptr);
			break;
		case SDL_KEYUP:
			_keys = SDL_GetKeyboardState(nullptr);
			break;
		}
	}
}

void hambourgeois::Engine::Update(float dt)
{
	if (_keys != nullptr)
	{
		if (_keys[SDL_SCANCODE_W]) {
			yPos -= 100 * dt;
		}
		if (_keys[SDL_SCANCODE_A]) {
			xPos -= 100 * dt;
		}
		if (_keys[SDL_SCANCODE_S]) {
			yPos += 100 * dt;
		}
		if (_keys[SDL_SCANCODE_D]) {
			xPos += 100 * dt;
		}

	}
}

void hambourgeois::Engine::Render()
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);

	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);

	int w, h;

	SDL_GetWindowSize(_window, &w, &h);

	SDL_Rect rect = { (w / 2 - 25) + xPos, (h / 2 - 25) + yPos, 50, 50 };

	SDL_RenderFillRect(_renderer, &rect);

	SDL_RenderPresent(_renderer);
}

void hambourgeois::Engine::Shutdown()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}