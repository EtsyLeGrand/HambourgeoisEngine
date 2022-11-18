#include <Scene.h>

Entity* Scene::Instantiate(const std::string& name)
{
	return hambourgeois::Engine::Get().World().Create(name);
}
