#pragma once

#include <Scene.h>
#include <map>

class Entity;

class WorldService : public hambourgeois::IWorld {
public:
	virtual ~WorldService() override;
	virtual void Update(float dt);
	virtual void Draw();
	virtual void Add(Entity* entity);
	virtual void Remove(Entity* entity);
	virtual Entity* Find(const std::string& name);
	virtual Entity* Create(const std::string& name);

	virtual void Load(const std::string& scene);
	virtual void Register(const std::string& name, Scene* scene);
	virtual void Unload();

private:

	std::vector<Entity*> entitiesInWorld;
	std::map<std::string, Entity*> entityMap;

	std::map<std::string, Scene*> scenes;
	Scene* currentScene = nullptr;
};