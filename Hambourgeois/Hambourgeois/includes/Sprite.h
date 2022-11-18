#pragma once

#include <Component.h>
#include <IDrawable.h>

class Sprite : public Component, public IDrawable
{
public:
	Sprite(Entity* entity);
	virtual void SetTexture(const std::string& filename);
	hambourgeois::RectI src = { 0, 0, 0, 0 };
	hambourgeois::RectF dest = { 0, 0, 1, 1 };
	hambourgeois::Flip flip = { 0, 0 };
	hambourgeois::Color color = hambourgeois::Color::WHITE;

protected:
	size_t texture_id = NULL;

private:
	virtual void Draw() override;
};