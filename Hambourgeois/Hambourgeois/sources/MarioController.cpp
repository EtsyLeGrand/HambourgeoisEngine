#include <MarioController.h>
#include <Entity.h>
#include <IInput.h>
#include <PhysicsObject.h>
#include <Animation.h>

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
	if (isRightPressed()) { 
		physicsObject->SetHSpeed(marioSpeed); 
		animation->SetFlip(true, false);
		animation->SetLoop(true);
	} else if (isLeftPressed()) { 
		physicsObject->SetHSpeed(-marioSpeed);
		animation->SetFlip(false, false);
		animation->SetLoop(true);
	} else { 
		physicsObject->SetHSpeed(0); 
		animation->Stop();
		animation->Play("walk", false);
	}

	if (isJumpPressed() && jumpKeyReleased)
	{
		physicsObject->SetVSpeed(-jumpForce);
		jumpKeyReleased = false;
	}
	else if (!isJumpPressed() && !jumpKeyReleased)
	{
		jumpKeyReleased = true;
	}
}

bool hambourgeois::MarioController::isRightPressed()
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

bool hambourgeois::MarioController::isLeftPressed()
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

bool hambourgeois::MarioController::isUpPressed()
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

bool hambourgeois::MarioController::isDownPressed()
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

bool hambourgeois::MarioController::isJumpPressed()
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

