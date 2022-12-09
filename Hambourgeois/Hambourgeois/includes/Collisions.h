#pragma once
#include <ICollisions.h>
#include <map>
#include <vector>

namespace hambourgeois
{
    class LineCollider;

    class Collisions : public ICollisions
    {
    public:
        virtual bool CheckPointCircle(float px, float py, float cx, float cy, float cr) override;
        virtual bool CheckPointRect(float px, float py, float rx, float ry, float rw, float rh) override;
        virtual bool CheckRects(float r1x, float r1y, float r1w, float r1h, float r2x, float r2y, float r2w, float r2h) override;
        virtual bool CheckRectCircle(float rx, float ry, float rw, float rh, float cx, float cy, float cr) override;
        virtual bool CheckLineRect(float l1x, float l1y, float l2x, float l2y, float rx, float ry, float rw, float rh) override;
        virtual bool CheckLineCircle(float l1x, float l1y, float l2x, float l2y, float cx, float cy, float cr) override;

        virtual void AddToLayer(const std::string& layerName, Entity* entity) override;
        virtual bool CollidesWithFloorLayer(Entity* entity, Entity** other) override;
        virtual bool CollidesWithLayer(Entity* entity, const std::string& layerName, Entity** other) override;
        virtual void Remove(Entity* entity) override;

    private:
        bool LineIntersectsEdge(float l1x, float l1y, float l2x, float l2y, float x1, float y1, float x2, float y2);
        std::map<std::string, std::vector<Entity*>> m_Layers;
    };
}