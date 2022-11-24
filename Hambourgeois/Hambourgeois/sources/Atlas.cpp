#include <Atlas.h>
#include <Engine.h>
using namespace hambourgeois;
Atlas::Atlas() : Atlas(nullptr)
{
}

Atlas::Atlas(Entity* parent) : Sprite(parent)
{
}

void Atlas::AddFrame(const std::string& name, int x, int y, int w, int h)
{
    frames.emplace(name, RectI{ x, y, w, h });

    if (frames.size() == 1)
    {
        SetFrame(name);
    }
}

void Atlas::SetFrame(const std::string& name)
{
    RectI _src = frames[name];
    source.x = _src.x;
    source.y = _src.y;
    source.w = _src.w;
    source.h = _src.h;
}