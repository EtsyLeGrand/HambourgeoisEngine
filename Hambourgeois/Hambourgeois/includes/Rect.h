#pragma once

namespace hambourgeois
{
    struct RectF
    {
        float x;
        float y;
        float w;
        float h;

        float GetX(int corner) {
            if (corner == 0) return x;
            if (corner == 1) return x + w;
            if (corner == 2) return x + w;
            if (corner == 3) return x;
        }

        float GetY(int corner) {
            if (corner == 0) return y;
            if (corner == 1) return y;
            if (corner == 2) return y + h;
            if (corner == 3) return y + h;
        }
    };

    struct RectI
    {
        int x;
        int y;
        int w;
        int h;
    };

    struct Flip
    {
        bool h;
        bool v;
    };
}