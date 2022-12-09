#include <LineCollider.h>
#include <Engine.h>
#include <Entity.h>
#include <Rect.h>

hambourgeois::LineCollider::LineCollider() : LineCollider(nullptr)
{
}

hambourgeois::LineCollider::LineCollider(Entity* parent) : Collider(parent)
{
	RectF rect = parent->GetRect();

	p1x = rect.x;
	p1y = rect.y;
	p2x = rect.x + rect.w;
	p2y = rect.y + rect.h;
}

void hambourgeois::LineCollider::Start()
{
	hambourgeois::Engine::Get().Collisions().AddToLayer("floor", entity);
}

void hambourgeois::LineCollider::Draw()
{
	if (canDraw)
	{
		hambourgeois::Engine::Get().Graphics().DrawLine(p2x, p2y, p1x, p1y, Color::LIMEGREEN);
	}
}


void hambourgeois::LineCollider::LineFromRect(bool isInverted)
{
	RectF rect = entity->GetRect();

	p1x = rect.x;
	p2x = rect.x + rect.w;

	if (isInverted)
	{
		p1y = rect.y + rect.h;
		p2y = rect.y;
	}
	else
	{
		p1y = rect.y;
		p2y = rect.y + rect.h;
	}
}
