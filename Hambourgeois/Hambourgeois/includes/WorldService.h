#pragma once
#include <vector>
#include <map>
#include <string>

class Entity;
class WorldService {
private:
	std::vector<Entity*> entitiesInWorld;
	std::map<std::string, Entity*> entityMap;

public:
	void Update(float dt);
	void Draw();
	void Add(Entity* entity);
	void Remove(Entity* entity);
	Entity* Find(const std::string& name);
};