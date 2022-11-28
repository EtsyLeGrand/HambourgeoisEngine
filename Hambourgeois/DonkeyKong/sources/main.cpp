#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN

#include <windows.h>
#include <Engine.h>
#include <BaseScene.h>
#include <Animation.h>
#include <MarioController.h>
#include <Animation.h>
#include <PhysicsObject.h>
#include <Canvas.h>

class MainMenu : public hambourgeois::BaseScene {
public:
	virtual void Load();
	virtual void Update(float dt);
};

class Level1 : public hambourgeois::BaseScene {
public:
	virtual void Load();
	virtual void Update(float dt);
};


void InitGameplay(hambourgeois::Engine& engine)
{
	engine.World().Register("MainMenu", new MainMenu());
	engine.World().Register("Level1", new Level1());
	engine.World().Load("MainMenu");

	
	
	/*engine.World().Unload();
	engine.World().Load("Level1");*/
}

INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR argv, _In_ INT argc)
{
	hambourgeois::Engine& engine = hambourgeois::Engine::Get();
	if (engine.Init("Donkey Kong", 224 * 3, 256 * 3))
	{
		InitGameplay(engine);
		engine.Start();
	}
	return 0;
}

void Level1::Load()
{

}

void Level1::Update(float dt)
{
}

void MainMenu::Load()
{
	hambourgeois::Engine& engine = hambourgeois::Engine::Get();
	int w, h;
	engine.Graphics().GetWindowSize(&w, &h);

	engine.Audio().PlayMusic(engine.Audio().LoadMusic("ressources/audio/loop.mp3"), -1);
	engine.Audio().SetVolume(75);

#pragma region Background
	hambourgeois::Entity* background;
	background = Instantiate("Background");
	hambourgeois::Sprite* bckSprite = background->AddComponent<hambourgeois::Sprite>();
	bckSprite->Load("ressources/images/25m.png");
	background->SetSize(224 * 3, 256 * 3);
#pragma endregion

	size_t font = engine.Graphics().LoadFont("ressources/fonts/dk.ttf", 20);
	hambourgeois::Entity* ui;
	ui = Instantiate("UI");
	hambourgeois::Canvas* canvas = ui->AddComponent<hambourgeois::Canvas>();
	canvas->AddText("1UP", "1UP", font, 55, 0, hambourgeois::Color::RED);
	canvas->AddText("Score", "000000", font, 10, 25, hambourgeois::Color::WHITE);
	canvas->AddText("HighScore", "000000", font, (w / 2) - 70.0f, 25, hambourgeois::Color::WHITE);
	canvas->AddText("Level", "01", font, 560.0f, 72.5f, hambourgeois::Color::BLUE);
	canvas->AddText("Bonus", "5000", font, 533.0f, 144.5f, hambourgeois::Color::AQUA);


	hambourgeois::Entity* mario;
	mario = Instantiate("Mario");
	mario->SetPosition(20.0f, 695.0f);
	mario->SetSize(16 * 3, 16 * 3);

	hambourgeois::Animation* marioAnim = mario->AddComponent<hambourgeois::Animation>();
	marioAnim->Load("ressources/images/mario_walk.png");
	marioAnim->Init(4, 16, 16);
	marioAnim->AddClip("walk", 0, 4, 0.1f);
	marioAnim->SetFlip(true, false);

	hambourgeois::PhysicsObject* marioPhysics = mario->AddComponent<hambourgeois::PhysicsObject>();
	marioPhysics->SetGravity(-9.8f);
	marioPhysics->SetTerminalVelocity(0.0f);

	hambourgeois::MarioController* controller = mario->AddComponent<hambourgeois::MarioController>();
	controller->setMarioSpeed(75.0f);
	controller->setJumpForce(225.0f);

	hambourgeois::Entity* dk;
	dk = Instantiate("Douneki Koungne");
	dk->SetPosition(100, 125);
	dk->SetSize(44 * 3, 32 * 3);

	/*
	hambourgeois::Animation* anim = dk->AddComponent<hambourgeois::Animation>();
	anim->Load("ressources/images/dk.png");
	anim->Init(4, 44, 32);
	anim->AddClip("frame1", 0, 4, 1);
	anim->Play("frame1", true);
	*/

	
	

}

void MainMenu::Update(float dt)
{
}
