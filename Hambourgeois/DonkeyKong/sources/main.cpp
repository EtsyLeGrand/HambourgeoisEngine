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
}