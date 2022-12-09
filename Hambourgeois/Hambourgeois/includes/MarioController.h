#pragma once
#include <Component.h>
#include <IUpdatable.h>
#include <EKey.h>

namespace hambourgeois
{
    class PhysicsObject;
    class Animation;

    class MarioController : public Component, public IUpdatable
    {
    public:
        virtual ~MarioController() = default;
        MarioController();
        MarioController(Entity* parent);

        enum PlayerState
        {
            Walking,
            Climbing
        };

        virtual void Update(float dt) override;

        /// <summary>
        /// Has the "right" key been pressed?
        /// </summary>
        /// <returns></returns>
        bool IsRightPressed();
        /// <summary>
        /// Has the "left" key been pressed?
        /// </summary>
        /// <returns></returns>
        bool IsLeftPressed();
        /// <summary>
        /// Has the "up" key been pressed?
        /// </summary>
        /// <returns></returns>
        bool IsUpPressed();
        /// <summary>
        /// Has the "down" key been pressed?
        /// </summary>
        /// <returns></returns>
        bool IsDownPressed();
        /// <summary>
        /// Has the "jump" key been pressed?
        /// </summary>
        /// <returns></returns>
        bool IsJumpPressed();

        /// <summary>
        /// Sets Mario's speed via the physics object.
        /// </summary>
        /// <param name="speed"></param>
        void SetMarioSpeed(float speed) { marioSpeed = speed; }
        /// <summary>
        /// Sets Mario's jump force via the physics object.
        /// </summary>
        /// <param name="force"></param>
        void SetJumpForce(float force) { jumpForce = force; }

    private:
        /// <summary>
        /// Handler for ladders
        /// </summary>
        void HandleLadderCollisions();
        /// <summary>
        /// Handler for the floor
        /// </summary>
        bool HandleFloorCollisions();
        /// <summary>
        /// Handler for the player movement / inputs
        /// </summary>
        void HandleMovement();
        /// <summary>
        /// Handler for the climbing state
        /// </summary>
        /// <param name="dt">: the delta time value</param>
        void HandleClimb(float dt);
        
        /// <summary>
        /// The player's state
        /// </summary>
        PlayerState state = Walking;

        float marioSpeed;
        float jumpForce;

        int currentFloor = 0;

        EKey keyRight[2] = { EKey::EKEY_D, EKey::EKEY_RIGHT };
        EKey keyLeft[2] = { EKey::EKEY_A, EKey::EKEY_LEFT };
        EKey keyUp[2] = { EKey::EKEY_W, EKey::EKEY_UP};
        EKey keyDown[2] = { EKey::EKEY_S, EKey::EKEY_DOWN };
        EKey keyJump[2] = { EKey::EKEY_SPACE, EKey::EKEY_X};

        Entity* ladderInRange = nullptr;

        PhysicsObject* physicsObject; // Requirement
        Animation* animation; // Requirement
    };
}
