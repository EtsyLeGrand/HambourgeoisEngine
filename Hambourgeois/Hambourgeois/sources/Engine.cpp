#include <Engine.h>
#include <Color.h>
#include <Rect.h>

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
#include <ConsoleLogger.h>
#include <FileLogger.h>


static unsigned char const* _keys = nullptr;
static bool isRunning = false;

static size_t dkid;
static size_t fontid;
static size_t soundid;
static size_t musicid;

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
	
	logger->Log("Initialization complete");
	return true;
}

void hambourgeois::Engine::Start()
{
	isRunning = true;

	dkid = graphics->LoadTexture("ressources/images/dk.png");
	fontid = graphics->LoadFont("ressources/fonts/AldotheApache.ttf", 100);
	soundid = audio->LoadSound("ressources/audio/coin.mp3");
	musicid = audio->LoadMusic("ressources/audio/barbies.wav");

	audio->PlaySFX(soundid);
	audio->PlayMusic(musicid);

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
			logger->Log("Exiting with keypress!");
			Exit();
		}
	}
}

void hambourgeois::Engine::Render()
{
	graphics->Clear();
	
	int w, h;
	graphics->GetWindowSize(&w, &h);

	RectI initialRect = { 1 + (47 * 0), 1, 44, 32 };
	RectF destRect = { 0, 0, 88, 64 };
	Flip noFlip, flip = { false, false };
	
	graphics->DrawTexture(dkid, initialRect, destRect, 0, noFlip, Color::WHITE);
	graphics->SetColor(Color::RED);
	
	
	RectF rect = { static_cast<int>((w / 2 - 25) + xPos), static_cast<int>((h / 2 - 25) + yPos), 50, 50 };

	graphics->FillRect(rect, Color::ROSYBROWN);
	graphics->DrawLine(0, 0, w, h, Color::ANTIQUEWHITE);
	graphics->DrawString("douneki koune!", fontid, w / 2 - 300, h / 2 - 200, Color::WHITE);
	
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
}