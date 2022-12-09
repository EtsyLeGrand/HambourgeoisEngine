#include <MarioController.h>
#include <Entity.h>
#include <Engine.h>
#include <PhysicsObject.h>
#include <Animation.h>
#include <LineCollider.h>
#include <LadderDropZone.h>

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
	switch (state)
	{
		case Walking:
			HandleLadderCollisions();
			HandleFloorCollisions();
			HandleMovement();
			break;
		case Climbing:
			HandleClimb(dt);
			break;
	}
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
	Entity* other = nullptr;
	if (IsUpPressed() && ladderInRange != nullptr)
	{
		state = Climbing;
		physicsObject->SetEnabled(false);
		entity->SetPosition(ladderInRange->GetX() - ladderInRange->GetWidth()/2, entity->GetY());
		animation->Play("climb", true);
		currentFloor++;
		return;
	}
	else if (IsDownPressed() && Engine::Get().Collisions().CollidesWithLayer(entity, "Ladder Dropzone", &other))
	{
		if (other->GetComponent<LadderDropZone>() != nullptr)
		{
			LadderDropZone* dropZone = other->GetComponent<LadderDropZone>();
			state = Climbing;
			physicsObject->SetEnabled(false);
			entity->SetPosition(dropZone->GetLinkedLadder()->GetX() - dropZone->GetLinkedLadder()->GetWidth() / 2, entity->GetY() + entity->GetHeight() + 10);
			// + 10 hardcodé. J'aurais pu le faire autrement, mais j'ai décidé de le faire avec une constante.
			animation->Play("climb", true);
			return;
		}
	}

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

void hambourgeois::MarioController::HandleClimb(float dt)
{
	if (IsUpPressed())
	{
		animation->Play("climb", true);
		entity->Translate(0, -marioSpeed * dt);
		HandleLadderCollisions();
		if (ladderInRange == nullptr)
		{
			state = Walking;
			physicsObject->SetEnabled(true);
		}
	}
	else if (IsDownPressed())
	{
		animation->Play("climb", true);
		entity->Translate(0, marioSpeed * dt);
		if (HandleFloorCollisions())
		{
			state = Walking;
			physicsObject->SetEnabled(true);
			currentFloor--;
		}
	}
	else
	{
		animation->Stop();
	}
}

void hambourgeois::MarioController::HandleLadderCollisions()
{
	hambourgeois::Entity* hit = nullptr;
	if (hambourgeois::Engine::Get().Collisions().CollidesWithLayer(entity, "Ladder", &hit)) {
		ladderInRange = hit;
	} else {
		ladderInRange = nullptr;
	}
}

bool hambourgeois::MarioController::HandleFloorCollisions()
{
	hambourgeois::Entity* hit = nullptr;
	if (hambourgeois::Engine::Get().Collisions().CollidesWithFloorLayer(entity, &hit))
	{
		hambourgeois::LineCollider* floor = hit->GetComponent<LineCollider>();

		//Pour faire en sorte de ne pas passer sous le plancher.
		//Si tu veux tester, tu peux décommenter. J'avais presque fini.
		/*if (floor->GetFloor() != currentFloor)
		{
			return false;
		}*/

		float slope = (floor->GetSlope());
		float xCenter = entity->GetX() + (entity->GetWidth() / 2);
		float yCenter = entity->GetY() + (entity->GetHeight() / 2);

		float y = slope * (xCenter - floor->GetP1x()) + floor->GetP1y();
		float dist = yCenter - y;

		entity->Translate(0, -dist - entity->GetHeight() / 2);

		return true;
	}
	return false;
}

