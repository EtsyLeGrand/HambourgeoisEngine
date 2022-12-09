#pragma once

#include <vector>
#include <string>
#include <map>
#include "IWorld.h"

namespace hambourgeois
{
    class Entity;
    class BaseScene;
    class WorldService : public IWorld
    {
    public:
        virtual ~WorldService() = default;

        virtual Entity* Create(const std::string& name) override;
        virtual void Update(float dt) override;
        virtual void Draw() override;
        virtual void Shutdown() override;
        virtual Entity* Find(const std::string& name) override;
        virtual void Remove(const std::string& name) override;
        virtual void Remove(Entity* entity) override;
        virtual void Load(const std::string& sceneName) override;
        virtual void Unload() override;
        virtual void Register(const std::string& sceneName, BaseScene* scene) override;

    private:
        void CleanEntities();
        void StartEntities();
        void UpdateLoadScene();

        BaseScene* currentScene = nullptr;

        std::string sceneToLoad;

        std::vector<Entity*> entityInWorld;
        std::vector<Entity*> entityToRemove;
        std::vector<Entity*> entityToStart;
        std::map<std::string, Entity*> entityMap;
        std::map<std::string, BaseScene*> sceneRegistry;
    };
}