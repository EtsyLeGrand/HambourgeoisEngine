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
        /// <summary>
        /// Sets the horizontal speed of the player.
        /// </summary>
        /// <param name="hSpeed">: the speed value</param>
        void SetHSpeed(float hSpeed);
        /// <summary>
        /// Sets the vertical speed of the player.
        /// </summary>
        /// <param name="hSpeed">: the speed value</param>
        void SetVSpeed(float vSpeed);
        /// <summary>
        /// Sets the speed of the player.
        /// </summary>
        /// <param name="hSpeed">: the horizontal speed</param>
        /// <param name="vSpeed">: the vertical speed</param>
        void SetSpeed(float hSpeed, float vSpeed);

        /// <summary>
        /// Sets the terminal velocity. This is the max speed at which the player can fall.
        /// </summary>
        /// <param name="termVel"></param>
        void SetTerminalVelocity(float termVel);

        /// <summary>
        /// An enabler / disabler. Useful when the physics object isn't always needed.
        /// </summary>
        /// <param name="_enabled"></param>
        void SetEnabled(bool _enabled) { enabled = _enabled; }

        float GetHSpeed() const { return horizontalSpeed; }
        float GetVSpeed() const { return verticalSpeed; }
        float GetTerminalVelocity() const { return terminalVelocity;  }

    private:
        float enabled = true;
        float gravity = -9.8f; // earth gravity
        float horizontalSpeed = 0.0f;
        float verticalSpeed = 0.0f;
        float terminalVelocity = -1.0f; // none by default
    };
}
