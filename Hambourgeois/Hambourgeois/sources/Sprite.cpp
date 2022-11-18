#include <Sprite.h>
#include <Entity.h>

Sprite::Sprite(Entity* entity) : Component(entity)
{
	this->entity = entity;
	dest.x = this->entity->x();
	dest.y = this->entity->y();
	dest.w = this->entity->w();;
	dest.h = this->entity->h();
}

void Sprite::SetTexture(const std::string& filename)
{
	texture_id = Graphics().LoadTexture(filename);
	if (texture_id != NULL)
	{
		Graphics().GetTextureSize(texture_id, &src.w, &src.h);
	}
}

void Sprite::Draw()
{
	dest.x = this->entity->x();
	dest.y = this->entity->y();
	if (texture_id != NULL)
	{
		Graphics().DrawTexture(texture_id, src, dest, 0, flip, color);
	}
}
