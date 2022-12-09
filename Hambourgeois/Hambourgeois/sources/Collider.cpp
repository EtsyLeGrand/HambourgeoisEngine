#include <Collider.h>
#include <Engine.h>
#include <Entity.h>
#include <Rect.h>

hambourgeois::Collider::Collider() : Collider(nullptr)
{
}

hambourgeois::Collider::Collider(Entity* parent) : Component(parent)
{
}

void hambourgeois::Collider::Start()
{
	hambourgeois::Engine::Get().Collisions().AddToLayer(layerName, entity);
}

void hambourgeois::Collider::Draw()
{
	if (canDraw)
	{
		hambourgeois::Engine::Get().Graphics().FillRect(entity->GetRect(), color);
	}
}

void hambourgeois::Collider::Destroy()
{
	hambourgeois::Engine::Get().Collisions().Remove(entity);
}

void hambourgeois::Collider::SetLayer(std::string _layerName)
{
	Destroy();
	layerName = _layerName;
	Start();
}

void hambourgeois::Collider::SetColor(const Color& col)
{
	color.Set(col);
}
