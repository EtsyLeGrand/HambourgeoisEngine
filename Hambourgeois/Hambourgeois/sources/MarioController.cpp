#include <MarioController.h>
#include <Entity.h>
#include <Engine.h>
#include <PhysicsObject.h>
#include <Animation.h>
#include <LineCollider.h>

static bool jumpKeyReleased = true;

hambourgeois::MarioController::MarioController() : MarioController(nullptr)
{
}

hambourgeois::MarioController::MarioController(Entity* parent) : Component(parent)
{
	physicsObject = entity->GetComponent<PhysicsObject>();
	animation = entity->GetComponent<Animation>();
	marioSpeed = physicsObject->GetHSpeed();
	jumpForce = 0.0f;
}

void hambourgeois::MarioController::Update(float dt)
{
	HandleFloorCollisions();
	HandleMovement();
	


}

bool hambourgeois::MarioController::IsRightPressed()
{
	for (int i = 0; i < sizeof(keyRight) / sizeof(int); i++)
	{
		if (Input().IsKeyDown(static_cast<int>(keyRight[i])))
		{
			return true;
		}
	}
	return false;
}

bool hambourgeois::MarioController::IsLeftPressed()
{
	for (int i = 0; i < sizeof(keyLeft) / sizeof(int); i++)
	{
		if (Input().IsKeyDown(static_cast<int>(keyLeft[i])))
		{
			return true;
		}
	}
	return false;
}

bool hambourgeois::MarioController::IsUpPressed()
{
	for (int i = 0; i < sizeof(keyUp) / sizeof(int); i++)
	{
		if (Input().IsKeyDown(static_cast<int>(keyUp[i])))
		{
			return true;
		}
	}
	return false;
}

bool hambourgeois::MarioController::IsDownPressed()
{
	for (int i = 0; i < sizeof(keyDown) / sizeof(int); i++)
	{
		if (Input().IsKeyDown(static_cast<int>(keyDown[i])))
		{
			return true;
		}
	}
	return false;
}

bool hambourgeois::MarioController::IsJumpPressed()
{
	for (int i = 0; i < sizeof(keyJump) / sizeof(int); i++)
	{
		if (Input().IsKeyDown(static_cast<int>(keyJump[i])))
		{
			return true;
		}
	}
	return false;
}

void hambourgeois::MarioController::HandleMovement()
{
	if (IsRightPressed()) {
		physicsObject->SetHSpeed(marioSpeed);
		animation->SetFlip(true, false);
		animation->SetLoop(true);
	}
	else if (IsLeftPressed()) {
		physicsObject->SetHSpeed(-marioSpeed);
		animation->SetFlip(false, false);
		animation->SetLoop(true);
	}
	else {
		physicsObject->SetHSpeed(0);
		animation->Stop();
		animation->Play("walk", false);
	}

	if (IsJumpPressed() && jumpKeyReleased)
	{
		physicsObject->SetVSpeed(-jumpForce);
		jumpKeyReleased = false;
	}
	else if (!IsJumpPressed() && !jumpKeyReleased)
	{
		jumpKeyReleased = true;
	}
}

void hambourgeois::MarioController::HandleFloorCollisions()
{
	hambourgeois::Entity* hit = nullptr;
	if (hambourgeois::Engine::Get().Collisions().CollidesWithFloorLayer(entity, &hit))
	{
		hambourgeois::LineCollider* floor = hit->GetComponent<LineCollider>();

		float slope = (floor->GetSlope());
		float xCenter = entity->GetX() + (entity->GetWidth() / 2);
		float yCenter = entity->GetY() + (entity->GetHeight() / 2);

		float y = slope * (xCenter - floor->GetP1x()) + floor->GetP1y();
		float dist = yCenter - y;

		entity->Translate(0, -dist - entity->GetHeight() / 2);

	}
}

