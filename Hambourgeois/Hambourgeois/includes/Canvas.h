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

        /// <summary>
        /// Adds a text to the canvas.
        /// </summary>
        /// <param name="id">: the text's unique id</param>
        /// <param name="text">: the actual text</param>
        /// <param name="fontId">: the font id</param>
        /// <param name="x">: the x position of the text</param>
        /// <param name="y">: the y position of the text</param>
        /// <param name="color">: the color of the text</param>
        void AddText(const std::string& id, std::string text, size_t fontId,
            float x, float y, const hambourgeois::Color color);

        /// <summary>
        /// Edits an existing text in the canvas.
        /// </summary>
        /// <param name="id">: the text's unique id</param>
        /// <param name="text">: the actual text</param>
        /// <param name="fontId">: the font id</param>
        /// <param name="x">: the x position of the text</param>
        /// <param name="y">: the y position of the text</param>
        /// <param name="color">: the color of the text</param>
        void EditText(const std::string& id, std::string text, size_t fontId,
            float x, float y, const hambourgeois::Color color);

        /// <summary>
        /// Edits an existing text in the canvas.
        /// </summary>
        /// <param name="id">: the text's unique id</param>
        /// <param name="text">: the actual text</param>
        void EditText(const std::string& id, std::string text);

        /// <summary>
        /// Removes a text from the canvas.
        /// </summary>
        /// <param name="id">: the text's unique id</param>
        void RemoveText(const std::string& id);

    private:
        std::map<const std::string, TextAtPosition> textMap;
    };
}