#pragma once
#include <string>
#include <map>
#include <vector>
#include <Component.h>
#include <IUpdatable.h>
#include <IDrawable.h>
#include <Rect.h>

namespace hambourgeois
{
    class Entity final
    {
    public:
        virtual ~Entity() = default;
        Entity(const std::string& name);

        virtual void Start();
        virtual void Update(float dt);
        virtual void Draw();
        virtual void Destroy();

        std::string& GetName() { return name; }

        void SetPosition(float _x, float _y)
        {
            x = _x;
            y = _y;
        }

        void SetSize(float w, float h)
        {
            width = w;
            height = h;
        }

        void SetRotation(double _angle)
        {
            angle = _angle;
        }

        void Translate(float dx, float dy)
        {
            x += dx;
            y += dy;
        }

        void Scale(float _dw, float _dh)
        {
            width *= _dw;
            height *= _dh;
        }

        void Rotate(double _angle)
        {
            angle += _angle;
        }

        void GetPosition(float* _x, float* _y)
        {
            *_x = x;
            *_y = y;
        }

        float GetX() const { return x; }
        float GetY() const { return y; }

        void GetSize(float* _w, float* _h)
        {
            *_w = width;
            *_h = height;
        }

        float GetWidth() const { return width; }
        float GetHeight() const { return height; }

        double GetRotation() const { return angle; }

        void GetRect(RectF* rect)
        {
            *rect = {
                x, y,
                width, height
            };
        }

        template <typename T>
        T* AddComponent()
        {
            T* component = new T(this);
            const type_info* type = &typeid(*component);
            if (componentsByType.count(type) == 0)
            {
                componentsByType.emplace(type, component);

                auto _updatable = dynamic_cast<IUpdatable*>(component);
                if (_updatable != nullptr)
                {
                    updatableComponents.emplace_back(_updatable);
                }

                auto _drawable = dynamic_cast<IDrawable*>(component);
                if (_drawable != nullptr)
                {
                    drawableComponents.emplace_back(_drawable);
                }

                return component;
            }

            return nullptr;
        }

        template <typename T>
        T* GetComponent()
        {
            const type_info* type = &typeid(T);
            if (componentsByType.count(type) > 0)
            {
                return static_cast<T*>(componentsByType[type]);
            }

            return nullptr;
        }

    protected:
        std::string name;

        std::map<const type_info*, Component*> componentsByType;
        std::vector<IUpdatable*> updatableComponents;
        std::vector<IDrawable*> drawableComponents;

        float x = 0.0f;
        float y = 0.0f;
        double angle = 0.0;
        float width = 1.0f;
        float height = 1.0f;
    };
}
