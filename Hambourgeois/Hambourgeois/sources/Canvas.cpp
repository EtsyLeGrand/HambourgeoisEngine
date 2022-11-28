#include "..\includes\Canvas.h"
#include <IGraphics.h>

hambourgeois::Canvas::Canvas() : Canvas(nullptr)
{
}

hambourgeois::Canvas::Canvas(Entity* parent) : Component(parent)
{
}

void hambourgeois::Canvas::Draw()
{
	for (auto pair : textMap)
	{
		auto val = pair.second;
		Graphics().DrawString(val.text, val.fontId, val.x, val.y, val.color);
	}
}

void hambourgeois::Canvas::AddText(const std::string& id, std::string text, size_t fontId, float x, float y, const hambourgeois::Color color)
{
	TextAtPosition newText = { text, fontId, x, y, color };
	textMap.emplace(id, newText);
}

void hambourgeois::Canvas::EditText(const std::string& id, std::string text, size_t fontId, float x, float y, const hambourgeois::Color color)
{
	if (textMap.find(id) != textMap.end()) {
		textMap.at(id).text = text;
		textMap.at(id).fontId = fontId;
		textMap.at(id).x = x;
		textMap.at(id).y = y;
		textMap.at(id).color = color;
	}
}

void hambourgeois::Canvas::RemoveText(const std::string& id)
{
	if (textMap.find(id) != textMap.end()) {
		textMap.erase(id);
	}
}
