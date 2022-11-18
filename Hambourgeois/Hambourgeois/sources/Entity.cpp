#include <Entity.h>

void Entity::Update(float dt)
{
	for (auto updatable : updatables)
	{
		updatable->Update(dt);
	}
}

void Entity::Draw()
{
	for (auto drawable : drawables)
	{
		drawable->Draw();
	}
}

void Entity::Destroy()
{
	auto it = --components.end();
	while (components.end() != it)
	{
		delete it->second;
		--it;
	}

	components.clear();

	updatables.clear();
	drawables.clear();
}