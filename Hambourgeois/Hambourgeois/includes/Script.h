#pragma once
#include <Component.h>
#include <IDrawable.h>
#include <IUpdatable.h>

// NOT IN USE!!!

namespace hambourgeois {
    class Script : public Component, public IDrawable, public IUpdatable
    {
    public:
        Script(Entity* ent);
        virtual void Draw() override;
        virtual void Update(float dt) override;
    };
}