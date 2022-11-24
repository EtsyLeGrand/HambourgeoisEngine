#pragma once
#include <Component.h>
#include <IDrawable.h>
#include <Color.h>
#include <Rect.h>
#include <string>

namespace hambourgeois
{
    class Sprite : public Component, public IDrawable
    {
    public:
        virtual ~Sprite() = default;
        Sprite();
        Sprite(Entity* parent);

        virtual void Draw() override;
        virtual void Load(const std::string& filename);

        void SetColor(const Color& color);
        void SetFlip(bool h, bool v);
        bool GetFlipH() const { return flip.h; }
        bool GetFlipV() const { return flip.v; }

    private:
        size_t textureId = 0;
        Color color{ 255, 255, 255, 255 };
        Flip flip;

    protected:
        RectI source{ 0, 0, 0, 0 };
    };
}
