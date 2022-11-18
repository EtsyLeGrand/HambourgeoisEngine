#pragma once
#include <Engine.h>

class Entity;

class Component
{
public:
	virtual ~Component() = default;
	Component();
	Component(Entity* parent);

	virtual void Start() {}
	virtual void Update() {}
	virtual void Draw() {}
	virtual void Destroy() {}

protected:
	Entity* entity = nullptr;

	hambourgeois::IInput& Input() const;
	hambourgeois::ILogger& Logger() const;
	hambourgeois::IGraphics& Graphics() const;
	hambourgeois::IServiceProvider& ServiceProvider() const;
	hambourgeois::IAudio& Audio() const;
};