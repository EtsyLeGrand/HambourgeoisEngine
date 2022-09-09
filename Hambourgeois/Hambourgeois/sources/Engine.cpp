#include <Engine.h>
#include <SDL.h>
#include <time.h>
#include <Windows.h>
#include <SdlInput.h>
#include <ConsoleLogger.h>
#include <FileLogger.h>
#include <iostream>

static SDL_Renderer* _renderer = nullptr;
static SDL_Window* _window = nullptr;
static unsigned char const* _keys = nullptr;
static bool isRunning = false;

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

	input = new SdlInput();
	
#if !_DEBUG
	logger = new ConsoleLogger();
#else
	logger = new FileLogger();
#endif
	logger->Log("Initialization complete");
	return true;
}

void hambourgeois::Engine::Start()
{
	isRunning = true;
	clock_t lastTime = clock();
	while (isRunning)
	{
		const clock_t start = clock();
		float dt = (start - lastTime) * 0.001f;

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
	Engine::input->Update();
}

void hambourgeois::Engine::Update(float dt)
{
	if (input != nullptr)
	{
		if (input->IsKeyDown(SDL_SCANCODE_W)) {
			yPos -= 100 * dt;
			logger->Log("W down!");
		}
		if (input->IsKeyDown(SDL_SCANCODE_A)) {
			xPos -= 100 * dt;
			logger->Log("A down!");
		}
		if (input->IsKeyDown(SDL_SCANCODE_S)) {
			yPos += 100 * dt;
			logger->Log("S down!");
		}
		if (input->IsKeyDown(SDL_SCANCODE_D)) {
			xPos += 100 * dt;
			logger->Log("D down!");
		}
		if (input->IsKeyDown(SDL_SCANCODE_ESCAPE)) {
			logger->Log("Exiting with Escape!");
			Exit();
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
	logger->Log("Shutting down...");
	if (input != nullptr)
		delete input;

	if (logger != nullptr)
		delete logger;

	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}