#include "PhysicsObject.h"
#include <Entity.h>
#include <Animation.h>
#include <PhysicsObject.h>

hambourgeois::PhysicsObject::PhysicsObject() : PhysicsObject(nullptr)
{
}

hambourgeois::PhysicsObject::PhysicsObject(Entity* parent) : Component(parent)
{
}

void hambourgeois::PhysicsObject::Update(float dt)
{
	if (enabled)
	{
		float x, y;
		entity->GetPosition(&x, &y);

		verticalSpeed -= gravity;
		if (terminalVelocity != -1.0f && verticalSpeed > terminalVelocity)
		{
			verticalSpeed = terminalVelocity;
		}

		entity->SetPosition(x + (horizontalSpeed * dt), y + (verticalSpeed * dt));
	}
}

void hambourgeois::PhysicsObject::SetGravity(float g)
{
	gravity = g;
}

void hambourgeois::PhysicsObject::SetHSpeed(float hSpeed)
{
	horizontalSpeed = hSpeed;
}

void hambourgeois::PhysicsObject::SetVSpeed(float vSpeed)
{
	verticalSpeed = vSpeed;
}

void hambourgeois::PhysicsObject::SetSpeed(float hSpeed, float vSpeed)
{
	horizontalSpeed = hSpeed;
	verticalSpeed = vSpeed;
}

void hambourgeois::PhysicsObject::SetTerminalVelocity(float termVel)
{
	terminalVelocity = termVel;
}
