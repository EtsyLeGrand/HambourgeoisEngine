#include <Engine.h>
#include <SDL.h>
#include <SDL_image.h>
#include <time.h>
#include <Windows.h>
#include <SdlInput.h>
#include <SdlGraphics.h>
#include <ConsoleLogger.h>
#include <FileLogger.h>
#include <iostream>
#include <vld.h>
#include <Color.h>
#include <Rect.h>

static SDL_Renderer* _renderer = nullptr;
static SDL_Window* _window = nullptr;
static unsigned char const* _keys = nullptr;
static bool isRunning = false;

static SDL_Texture* dkTexture = nullptr;

static const float TARGET_FPS = 60.0f;
static const float MS_PER_FRAME = (1000 / TARGET_FPS);

static float xPos = 0;
static float yPos = 0;

bool hambourgeois::Engine::Init(const std::string& title, int w, int h)
{
#if _DEBUG
	logger = new ConsoleLogger();
#else
	logger = new FileLogger();
#endif

	logger->Log("Initialization complete");

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		logger->Log(SDL_GetError());
		return false;
	}

	graphics = new SdlGraphics();
	graphics->Initialize("Donki kounge", 800, 600);
	input = new SdlInput();
	
	
	return true;
}

void hambourgeois::Engine::Start()
{
	isRunning = true;

	dkTexture = IMG_LoadTexture(_renderer, "ressources/images/dk.png");

	clock_t lastTime = clock();

	while (isRunning)
	{
		const clock_t start = clock();
		float dt = (start - lastTime) * 0.001f;

		ProcessInput();
		Update(dt);
		Render();

		float sleepAmount = start + (MS_PER_FRAME - clock());
		if (sleepAmount > 0) Sleep(static_cast<DWORD>(sleepAmount));

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
	graphics->SetColor(Color::WHITE);

	graphics->Clear();

	SDL_Rect initialRect = { 1 + (47 * 0), 1, 44, 32 };
	SDL_Rect destRect = { 100, 100, 88, 64 };
	
	//graphics->DrawTexture();
	SDL_RenderCopyEx(_renderer, dkTexture, &initialRect, &destRect, 0, NULL, SDL_FLIP_NONE);

	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
	
	int w, h;
	SDL_GetWindowSize(_window, &w, &h);

	SDL_Rect rect = { static_cast<int>((w / 2 - 25) + xPos), static_cast<int>((h / 2 - 25) + yPos), 50, 50 };

	//graphics->FillRect()
	SDL_RenderFillRect(_renderer, &rect);


	graphics->Present();
}

void hambourgeois::Engine::Shutdown()
{
	logger->Log("Shutting down...");
	if (input != nullptr)
		delete input;

	if (logger != nullptr)
		delete logger;

	if (graphics != nullptr)
		delete graphics;

	SDL_Quit();
}