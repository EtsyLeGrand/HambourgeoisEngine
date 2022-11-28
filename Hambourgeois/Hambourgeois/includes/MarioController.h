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

        virtual void Update(float dt) override;

        bool isRightPressed();
        bool isLeftPressed();
        bool isUpPressed();
        bool isDownPressed();
        bool isJumpPressed();

        void setMarioSpeed(float speed) { marioSpeed = speed; }
        void setJumpForce(float force) { jumpForce = force; }

    private:
        float marioSpeed;
        float jumpForce;

        EKey keyRight[2] = { EKey::EKEY_D, EKey::EKEY_RIGHT };
        EKey keyLeft[2] = { EKey::EKEY_A, EKey::EKEY_LEFT };
        EKey keyUp[2] = { EKey::EKEY_W, EKey::EKEY_UP};
        EKey keyDown[2] = { EKey::EKEY_S, EKey::EKEY_DOWN };
        EKey keyJump[2] = { EKey::EKEY_SPACE, EKey::EKEY_X};

        PhysicsObject* physicsObject; // Requirement
        Animation* animation; // Requirement
    };
}
