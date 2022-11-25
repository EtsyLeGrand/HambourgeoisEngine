#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN

#include <windows.h>
#include <Engine.h>
#include <BaseScene.h>
#include <Sprite.h>

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

	hambourgeois::Entity* dk;
	dk = Instantiate("Douneki Koungne");
	dk->SetPosition(100, 125);
	dk->SetSize(300, 80);
	hambourgeois::Sprite* sprite = dk->AddComponent<hambourgeois::Sprite>();
	sprite->Load("ressources/images/dk.png");


}

void MainMenu::Update(float dt)
{
}
