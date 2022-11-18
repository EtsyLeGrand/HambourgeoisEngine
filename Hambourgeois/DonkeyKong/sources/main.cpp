#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN

#include <windows.h>
#include <Engine.h>
#include <Scene.h>
#include <Sprite.h>

class MainMenu : public Scene {
public:
	virtual void Load();
	virtual void Update(float dt);
};

class Level1 : public Scene {
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
	if (engine.Init("Donkey Kong", 800, 600))
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
	Entity* entite = engine.World().Create("dounki");
	entite->Set_X(25);
	entite->Set_Y(25);
	Sprite* sprite = entite->AddComponent<Sprite>();
	sprite->SetTexture("ressources/images/dk.png");
}

void MainMenu::Update(float dt)
{
}
