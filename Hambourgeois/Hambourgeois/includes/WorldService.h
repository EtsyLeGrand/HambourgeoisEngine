#pragma once
#include <vector>
#include <map>
#include <string>
#include <Scene.h>

class Entity;

class WorldService {
private:
	std::vector<Entity*> entitiesInWorld;
	std::map<std::string, Entity*> entityMap;

	std::map<std::string, hambourgeois::IScene*> scenes;
	hambourgeois::IScene* currentScene = nullptr;

public:
	Entity* Create(const std::string& name);
	void Update(float dt);
	void Draw();
	void Add(Entity* entity);
	void Remove(Entity* entity);
	Entity* Find(const std::string& name);

	void Load(const std::string& scene);
	void Register(const std::string& name, hambourgeois::IScene* scene);
	void Unload();
};