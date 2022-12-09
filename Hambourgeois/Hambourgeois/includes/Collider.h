#pragma once
#include <Component.h>
#include <IDrawable.h>
#include <Color.h>
#include <string>

namespace hambourgeois
{
    class Collider : public Component, public IDrawable
    {
    public:
        virtual ~Collider() = default;
        Collider();
        Collider(Entity* parent);

        virtual void Start() override;
        virtual void Draw() override;
        virtual void Destroy() override;

        void EnableDraw() { canDraw = true; };
        void DisableDraw() { canDraw = false; };

        void SetLayer(std::string _layerName);

        void SetColor(const Color& col);

    private:
        std::string layerName = "objects";
        bool canDraw = false;
        Color color{ 255, 255, 255, 255 };
    };
}
