#pragma once
#include <string>

namespace hambourgeois
{
    class Entity;

    class ICollisions
    {
    public:
        virtual ~ICollisions() = default;

        virtual bool CheckPointCircle(float px, float py, float cx, float cy, float cr) = 0;
        virtual bool CheckPointRect(float px, float py, float rx, float ry, float rw, float rh) = 0;
        virtual bool CheckRects(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h) = 0;
        virtual bool CheckRectCircle(float rx, float ry, float rw, float rh, float cx, float cy, float cr) = 0;
        virtual bool CheckLineRect(float l1x, float l1y, float l2x, float l2y, float rx, float ry, float rw, float rh) = 0;
        virtual bool CheckLineCircle(float l1x, float l1y, float l2x, float l2y, float cx, float cy, float cr) = 0;

        virtual void AddToLayer(const std::string& layerName, Entity* entity) = 0;
        virtual bool CollidesWithFloorLayer(Entity* entity, Entity** other) = 0;
        virtual bool CollidesWithLayer(Entity* entity, const std::string& layerName, Entity** other) = 0;
        virtual void Remove(Entity* entity) = 0;
    };
}