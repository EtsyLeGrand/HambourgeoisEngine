#include <WorldService.h>
#include <Entity.h>

Entity* WorldService::Create(const std::string& name)
{
	Entity* e = new Entity(name);
	Add(e);
	return e;
}

WorldService::~WorldService()
{
	Unload();
	for (auto scene : scenes)
	{
		delete scene.second;
	}
}

void WorldService::Update(float dt)
{
	for (auto entity : entitiesInWorld) {
		entity->Update(dt); 
	}
}

void WorldService::Draw()
{
	for (auto entity : entitiesInWorld) {
		entity->Draw();
	}
}

void WorldService::Add(Entity* entity)
{
	entitiesInWorld.emplace_back(entity);
	entityMap.emplace(entity->GetName(), entity);
}

void WorldService::Remove(Entity* entity)
{
	for (auto it = entityMap.begin(); it != entityMap.end(); ++it)
	{
		if (it->second->GetName() == entity->GetName()) {
			entityMap.erase(it);
			it--;
		}
	}

	for (auto it = entitiesInWorld.begin(); it != entitiesInWorld.end(); ++it)
	{
		if ((*it)->GetName() == entity->GetName()) {
			entitiesInWorld.erase(it);
			it--;
		}
	}
}

Entity* WorldService::Find(const std::string& name)
{
	if (entityMap.count(name) > 0) 
	{
		return entityMap[name];
	}
	return nullptr;
}

void WorldService::Load(const std::string& scene)
{
	if (scenes.count(scene) > 0)
	{
		Unload();
		currentScene = scenes[scene];
		scenes[scene]->Load();
	}
}

void WorldService::Register(const std::string& name, Scene* scene)
{
	if (scenes.count(name) == 0)
	{
		scenes[name] = scene;
	}
}

void WorldService::Unload()
{
	if (currentScene != nullptr)
	{
		for (auto entity : entitiesInWorld) {
			entity->Destroy();
			delete entity;
		}

		entitiesInWorld.clear();
		entityMap.clear();
	}
}
