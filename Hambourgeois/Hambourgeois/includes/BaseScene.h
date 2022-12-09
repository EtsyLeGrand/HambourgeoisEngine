#pragma once
#include <string>
#include <Entity.h>

namespace hambourgeois
{
    class BaseScene
    {
    public:
        virtual ~BaseScene() = default;
        virtual void Load() = 0;
        virtual void Update(float dt) = 0;

    protected:
        Entity* Instantiate(const std::string& name);
    };
}