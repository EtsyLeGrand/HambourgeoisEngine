#include <WorldService.h>
#include <BaseScene.h>
#include <Engine.h>

hambourgeois::Entity* hambourgeois::WorldService::Create(const std::string& name)
{
    Entity* newEntity = new Entity(name);

    if (entityMap.count(name) == 0)
    {
        entityToStart.emplace_back(newEntity);
        return newEntity;
    }

    return nullptr;
}

void hambourgeois::WorldService::Update(float dt)
{
    for (auto entity : entityInWorld)
    {
        entity->Update(dt);
    }

    UpdateLoadScene();

    StartEntities();
    CleanEntities();
}

void hambourgeois::WorldService::Draw()
{
    for (auto entity : entityInWorld)
    {
        entity->Draw();
    }
}

void hambourgeois::WorldService::Remove(Entity* entity)
{
    if (entity != nullptr)
    {
        Remove(entity->GetName());
    }
}

void hambourgeois::WorldService::Remove(const std::string& name)
{
    if (entityMap.count(name) > 0)
    {
        for (size_t i = 0; i < entityInWorld.size(); i++)
        {
            Entity* entity = entityInWorld[i];
            if (entity->GetName() == name)
            {
                entityToRemove.emplace_back(entity);
                break;
            }
        }
    }
}

hambourgeois::Entity* hambourgeois::WorldService::Find(const std::string& name)
{
    if (entityMap.count(name) > 0)
    {
        return entityMap[name];
    }

    return nullptr;
}

void hambourgeois::WorldService::Load(const std::string& scene)
{
    if (sceneRegistry.count(scene) > 0)
    {
        sceneToLoad = scene;
    }
}

void hambourgeois::WorldService::Register(const std::string& name, BaseScene* scene)
{
    if (sceneRegistry.count(name) == 0)
    {
        sceneRegistry[name] = scene;
    }
}

void hambourgeois::WorldService::Unload()
{
    for (auto entity : entityInWorld)
    {
        entity->Destroy();
        delete entity;
    }

    for (auto entity : entityToStart)
    {
        delete entity;
    }

    for (auto entity : entityToRemove)
    {
        entity->Destroy();
        delete entity;
    }

    entityInWorld.clear();
    entityMap.clear();
    entityToStart.clear();
    entityToRemove.clear();
}

void hambourgeois::WorldService::Shutdown()
{
    Unload();

    for (auto scene : sceneRegistry)
    {
        delete scene.second;
    }

    sceneRegistry.clear();
}

void hambourgeois::WorldService::CleanEntities()
{
    if (entityToRemove.size() > 0)
    {
        std::vector<Entity*> _trash = entityToRemove;
        entityToRemove.clear();

        for (auto entity : _trash)
        {
            entityMap.erase(entity->GetName());
            entity->Destroy();

            for (auto it = entityInWorld.begin(); it != entityInWorld.end(); ++it)
            {
                if (entity == *it)
                {
                    entityInWorld.erase(it);
                    delete entity;
                    break;
                }
            }
        }

        _trash.clear();
    }
}

void hambourgeois::WorldService::StartEntities()
{
    if (entityToStart.size() > 0)
    {
        std::vector<Entity*> starting = entityToStart;
        entityToStart.clear();

        for (auto entity : starting)
        {
            if (entityMap.count(entity->GetName()) > 0)
            {
                Engine::Get().Logger().Log("Not adding entity with same name");
                continue;
            }

            entityInWorld.emplace_back(entity);
            entityMap.emplace(entity->GetName(), entity);
        }

        for (auto entity : starting)
        {
            entity->Start();
        }

        starting.clear();
    }
}

void hambourgeois::WorldService::UpdateLoadScene()
{
    if (!sceneToLoad.empty())
    {
        Unload();
        sceneRegistry[sceneToLoad]->Load();
        sceneToLoad.clear();
    }
}