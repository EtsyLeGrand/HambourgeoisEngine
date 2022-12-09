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

        /// <summary>
        /// Enables drawing of the collider, for debug purposes.
        /// </summary>
        void EnableDraw() { canDraw = true; };
        /// <summary>
        /// Disables drawing of the collider.
        /// </summary>
        void DisableDraw() { canDraw = false; };

        /// <summary>
        /// Sets a new layer to the collider.
        /// </summary>
        /// <param name="_layerName">: the layer's name</param>
        void SetLayer(std::string _layerName);

        /// <summary>
        /// Sets a color to the drawn collider, for debug purposes.
        /// </summary>
        /// <param name="col"></param>
        void SetColor(const Color& col);

    protected:
        std::string layerName = "objects";
        bool canDraw = false;
        Color color{ 255, 255, 255, 255 };
    };
}
