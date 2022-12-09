#pragma once
#include <Sprite.h>
#include <map>
#include <string>
#include <IDrawable.h>
#include <Rect.h>

namespace hambourgeois
{
    struct TextAtPosition
    {
        std::string text;
        size_t fontId;
        float x, y;
        hambourgeois::Color color;
    };

    class Canvas final : public Component, public IDrawable
    {
    public:
        virtual ~Canvas() = default;
        Canvas();
        Canvas(Entity* parent);

        void Draw() override;

        void AddText(const std::string& id, std::string text, size_t fontId,
            float x, float y, const hambourgeois::Color color);

        void EditText(const std::string& id, std::string text, size_t fontId,
            float x, float y, const hambourgeois::Color color);

        void EditText(const std::string& id, std::string text);

        void RemoveText(const std::string& id);

    private:
        std::map<const std::string, TextAtPosition> textMap;
    };
}