#include <Collisions.h>
#include <math.h>
#include <Entity.h>
#include <LineCollider.h>
#include <algorithm>
#include <cmath>

bool hambourgeois::Collisions::CheckPointCircle(float px, float py, float cx, float cy, float cr)
{
    float vecX = px - cx;
    float vecY = py - cy;
    float d = sqrtf((vecX * vecX) + (vecY * vecY));

    return d <= cr;
}

bool hambourgeois::Collisions::CheckPointRect(float px, float py, float rx, float ry, float rw,
    float rh)
{
    return px >= rx && py >= ry && px <= (rx + rw) && py <= (ry + rh);
}

bool hambourgeois::Collisions::CheckRects(float r1x, float r1y, float r1w, float r1h, float r2x,
    float r2y, float r2w, float r2h)
{
    return (r1x <= (r2x + r2w) && (r1x + r1w) >= r2x &&
        r1y <= (r2y + r2h) && (r1y + r1h) >= r2y);
}

bool hambourgeois::Collisions::CheckRectCircle(float rx, float ry, float rw, float rh, float cx, float cy, float cr)
{
    if (CheckPointRect(cx, cy, rx, ry, rw, rh))
    {
        return true;
    }

    float tx = cx;
    float ty = cy;

    if (tx < rx) tx = rx;
    if (tx > rx + rw) tx = rx + rw;
    if (ty < ry) ty = ry;
    if (ty > ry + rh) ty = ry + rh;

    return CheckPointCircle(tx, ty, cx, cy, cr);
}

bool hambourgeois::Collisions::CheckLineRect(float l1x, float l1y, float l2x, float l2y, float rx, float ry, float rw, float rh)
{
    if (std::max(l1x, l2x) < rx || std::min(l1x, l2x) > rx + rw) {
        return false;
    }

    if (std::max(l1y, l2y) < ry || std::min(l1y, l2y) > ry + rh) {
        return false;
    }

    float slope = (l2y - l1y) / (l2x - l1x);

    // Check if the line is vertical and outside the rectangle in the y-direction.
    if (std::isinf(slope)) {
        return l1x >= rx && l1x <= rx + rw;
    }

    float intercept = l1y - slope * l1x;

    if (slope * rx + intercept > ry &&
        slope * rx + intercept < ry + rh) {
        return true;
    }

    if (slope * (rx + rw) + intercept > ry &&
        slope * (rx + rw) + intercept < ry + rh) {
        return true;
    }

    if (ry >= slope * rx + intercept &&
        ry <= slope * (rx + rw) + intercept) {
        return true;
    }

    if (ry + rh >= slope * rx + intercept &&
        ry + rh <= slope * (rx + rw) + intercept) {
        return true;
    }

    return false;
}

bool hambourgeois::Collisions::CheckLineCircle(float l1x, float l1y, float l2x, float l2y, float cx, float cy, float cr)
{
    float slope = (l2y - l1y) / (l2x - l1x);
    float intercept = l1y - (slope * l1x);

    bool center_side = (cy - cr > (slope * cx + intercept)) ==
        (cy + cr > (slope * cx + intercept));

    return (!center_side);
}

void hambourgeois::Collisions::AddToLayer(const std::string& layerName, Entity* entity)
{
    if (m_Layers.count(layerName) == 0)
    {
        m_Layers.emplace(layerName, std::vector<Entity*>());
    }

    m_Layers[layerName].push_back(entity);
}

bool hambourgeois::Collisions::CollidesWithFloorLayer(Entity* entity, Entity** other)
{
    *other = nullptr;

    if (m_Layers.count("floor") > 0)
    {
        float rx, ry, rw, rh;
        float l1x, l1y, l2x, l2y;

        entity->GetPosition(&rx, &ry);
        entity->GetSize(&rw, &rh);

        for (Entity* e : m_Layers["floor"])
        {
            LineCollider* line = e->GetComponent<LineCollider>();
            l1x = line->GetP1x();
            l2x = line->GetP2x();
            l1y = line->GetP1y();
            l2y = line->GetP2y();

            if (CheckLineRect(l1x, l1y, l2x, l2y, rx, ry, rw, rh))
            {
                *other = e;
                return true;
            }

        }
    }

    return false;
}


bool hambourgeois::Collisions::CollidesWithLayer(Entity* entity, const std::string& layerName, Entity** other)
{
    *other = nullptr;

    if (m_Layers.count(layerName) > 0)
    {
        float r1x, r1y, r1w, r1h;
        float r2x, r2y, r2w, r2h;

        entity->GetPosition(&r1x, &r1y);
        entity->GetSize(&r1w, &r1h);

        for (Entity* e : m_Layers[layerName])
        {
            e->GetPosition(&r2x, &r2y);
            e->GetSize(&r2w, &r2h);

            if (CheckRects(r1x, r1y, r1w, r1h, r2x, r2y, r2w, r2h))
            {
                *other = e;
                return true;
            }

        }
    }

    return false;
}

void hambourgeois::Collisions::Remove(Entity* entity)
{
    for (auto layer : m_Layers)
    {
        std::vector<Entity*>::iterator it = layer.second.begin();
        while (it != layer.second.end())
        {
            if (*it == entity)
            {
                layer.second.erase(it);
                return;
            }

            it++;
        }
    }
}
