#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN

#include <windows.h>
#include <Engine.h>

void InitGameplay()
{

}

INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR argv, _In_ INT argc)
{
	hambourgeois::Engine engine;
	if (engine.Init("Donkey Kong", 800, 600))
	{
		InitGameplay();
		engine.Start();
	}
	return 0;
<<<<<<< Updated upstream
}
=======
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
	entite->Set_W(84);
	entite->Set_H(30);
	Sprite* sprite = entite->AddComponent<Sprite>();
	sprite->SetTexture("ressources/images/dk.png");
}

void MainMenu::Update(float dt)
{
}
>>>>>>> Stashed changes
