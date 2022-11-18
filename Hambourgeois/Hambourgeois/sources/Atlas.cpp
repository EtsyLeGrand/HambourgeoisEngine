#include <Atlas.h>
#include <Entity.h>

Atlas::Atlas(Entity* entity): Sprite(entity)
{
	this->entity = entity;
}

void Atlas::AddFrame(const std::string& name, int x, int y, int w, int h)
{
	if (frameCache.find(name) == frameCache.end()) // not in cache
	{
		hambourgeois::RectI rect = { x, y, w, h };
		frameCache.insert(std::make_pair(name, rect));
	}	
}

void Atlas::SetFrame(const std::string& name)
{
	if (frameCache.find(name) != frameCache.end()) // in cache
	{
		frame = frameCache[name];
		dest.w = frame.w;
		dest.h = frame.h;
	}
}

void Atlas::Draw()
{
	dest.x = this->entity->x();
	dest.y = this->entity->y();
	if (texture_id != NULL)
	{
		Graphics().DrawTexture(texture_id, frame, dest, 0, flip, color);
	}
}
