#include "Sprite.h"
#include "Engine.h"
#include "Entity.h"
using namespace hambourgeois;


hambourgeois::Sprite::Sprite() : Sprite(nullptr)
{
}

hambourgeois::Sprite::Sprite(Entity* parent) : Component(parent)
{
    flip.h = false;
    flip.v = false;
}

void hambourgeois::Sprite::Draw()
{
    double _rot = entity->GetRotation();
    RectF _dst;
    entity->GetRect(&_dst);

    Graphics().DrawTexture(textureId, source, _dst, _rot, flip, color);
}

void hambourgeois::Sprite::Load(const std::string& filename)
{
    textureId = Graphics().LoadTexture(filename);
    Graphics().GetTextureSize(textureId, &source.w, &source.h);
}

void hambourgeois::Sprite::SetColor(const Color& color)
{
    //color.Set(color);
}

void hambourgeois::Sprite::SetFlip(bool h, bool v)
{
    flip.h = h;
    flip.v = v;
}