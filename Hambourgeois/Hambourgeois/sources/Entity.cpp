#include <Entity.h>

hambourgeois::Entity::Entity(const std::string& name) : name(name)
{
}

void hambourgeois::Entity::Start()
{
    for (auto it = componentsByType.begin(); it != componentsByType.end(); ++it)
    {
        it->second->Start();
    }
}

void hambourgeois::Entity::Update(float dt)
{
    for (auto component : updatableComponents)
    {
        component->Update(dt);
    }
}

void hambourgeois::Entity::Draw()
{
    for (auto component : drawableComponents)
    {
        component->Draw();
    }
}

void hambourgeois::Entity::Destroy()
{
    for (auto it = componentsByType.begin(); it != componentsByType.end(); ++it)
    {
        it->second->Destroy();
        delete it->second;
    }

    componentsByType.clear();
    drawableComponents.clear();
    updatableComponents.clear();
}