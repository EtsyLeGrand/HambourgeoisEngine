#include <Component.h>
#include <Entity.h>

Component::Component()
{
}

Component::Component(Entity* parent)
{
	entity = parent;
}

hambourgeois::IInput& Component::Input() const
{
	return hambourgeois::Engine::Get().Input();
}

hambourgeois::ILogger& Component::Logger() const
{
	return hambourgeois::Engine::Get().Logger();
}

hambourgeois::IGraphics& Component::Graphics() const
{
	return hambourgeois::Engine::Get().Graphics();
}

hambourgeois::IServiceProvider& Component::ServiceProvider() const
{
	return hambourgeois::Engine::Get().ServiceProvider();
}

hambourgeois::IAudio& Component::Audio() const
{
	return hambourgeois::Engine::Get().Audio();
}
