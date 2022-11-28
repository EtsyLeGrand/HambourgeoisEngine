#pragma once
#include <Component.h>
#include <IUpdatable.h>

namespace hambourgeois
{
    class PhysicsObject : public Component, public IUpdatable
    {
    public:
        virtual ~PhysicsObject() = default;
        PhysicsObject();
        PhysicsObject(Entity* parent);

        virtual void Update(float dt) override;

        void SetGravity(float g);
        void SetHSpeed(float hSpeed);
        void SetVSpeed(float vSpeed);
        void SetSpeed(float hSpeed, float vSpeed);

        void SetTerminalVelocity(float termVel);

        float GetHSpeed() const { return horizontalSpeed; }
        float GetVSpeed() const { return verticalSpeed; }
        float GetTerminalVelocity() const { return terminalVelocity;  }

    private:
        float gravity = -9.8f; // earth gravity
        float horizontalSpeed = 0.0f;
        float verticalSpeed = 0.0f;
        float terminalVelocity = -1.0f; // none by default
    };
}
