#include "Component.h"
#include <Engine.h>

hambourgeois::Component::Component() : Component(nullptr)
{
}

hambourgeois::Component::Component(Entity* parent) : entity(parent)
{
}

void hambourgeois::Component::Exit()
{
    Engine::Get().Exit();
}

hambourgeois::IInput& hambourgeois::Component::Input() const
{
    return Engine::Get().Input();
}

hambourgeois::ILogger& hambourgeois::Component::Logger() const
{
    return Engine::Get().Logger();
}

hambourgeois::IGraphics& hambourgeois::Component::Graphics() const
{
    return Engine::Get().Graphics();
}

hambourgeois::IAudio& hambourgeois::Component::Audio() const
{
    return Engine::Get().Audio();
}

hambourgeois::IWorld& hambourgeois::Component::World() const
{
    return Engine::Get().World();
}