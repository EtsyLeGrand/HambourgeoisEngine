#include <Engine.h>
#include <BaseScene.h>

#include <time.h>
#include <Windows.h>
#include <iostream>
#include <vld.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <SdlInput.h>
#include <SdlGraphics.h>
#include <SdlAudio.h>
#include <SdlServiceProvider.h>
#include <WorldService.h>
#include <Collisions.h>
#include <ConsoleLogger.h>
#include <FileLogger.h>

static bool isRunning = false;

static const float TARGET_FPS = 60.0f;
static const float MS_PER_FRAME = (1000 / TARGET_FPS);

static hambourgeois::Engine* engine;

hambourgeois::Engine& hambourgeois::Engine::Get()
{
	if (engine == nullptr)
	{
		engine = new Engine();
	}

	return *engine;
}

bool hambourgeois::Engine::Init(const std::string& title, int w, int h)
{
#if _DEBUG
	logger = new ConsoleLogger();
#else
	logger = new FileLogger();
#endif

	serviceProvider = new SdlServiceProvider();
	if (!serviceProvider->Initialize())
	{
		logger->Log("Couldn't Initialize Service Provider");
		return false;
	}
	else { logger->Log("Service Provider OK"); }

	graphics = new SdlGraphics();
	if (!graphics->Initialize(title, w, h))
	{
		logger->Log("Couldn't Initialize Graphics");
		return false;
	}
	else { logger->Log("Graphics Service OK"); }

	audio = new SdlAudio();
	if (!audio->Initialize())
	{
		logger->Log("Couldn't Initialize Audio");
		return false;
	}
	else { logger->Log("Audio Service OK"); }
	
	input = new SdlInput();

	world = new WorldService();
	if (world == nullptr)
	{
		logger->Log("Couldn't Initialize World");
		return false;
	}
	else { logger->Log("World Service OK"); }

	collisions = new hambourgeois::Collisions();
	
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
		if (input->IsKeyDown(SDL_SCANCODE_ESCAPE)) {
			logger->Log("Exiting with keypress!");
			Exit();
		}
	}

	if (world != nullptr)
	{
		world->Update(dt);
	}
}

void hambourgeois::Engine::Render()
{
	graphics->Clear();
	
	int w, h;
	graphics->GetWindowSize(&w, &h);

	if (world != nullptr)
	{
		world->Draw();
	}

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

	if (audio != nullptr)
		delete audio;

	if (serviceProvider != nullptr)
		delete serviceProvider;

	if (world != nullptr)
	{
		world->Shutdown();
		delete world;
	}

	if (collisions != nullptr)
		delete collisions;

	delete engine;
	engine = nullptr;
}