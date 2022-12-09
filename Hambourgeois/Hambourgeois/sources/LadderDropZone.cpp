#include <LadderDropZone.h>
#include <Engine.h>
#include <Entity.h>

hambourgeois::LadderDropZone::LadderDropZone() : LadderDropZone(nullptr)
{
}

hambourgeois::LadderDropZone::LadderDropZone(Entity* parent) : Component(parent)
{
}
