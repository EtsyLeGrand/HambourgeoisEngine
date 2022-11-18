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