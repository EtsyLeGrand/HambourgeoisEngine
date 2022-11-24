#include <BaseScene.h>
#include <Engine.h>

hambourgeois::Entity* hambourgeois::BaseScene::Instantiate(const std::string& name)
{
    return Engine::Get().World().Create(name);
}