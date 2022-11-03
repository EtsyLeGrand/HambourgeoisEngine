#pragma once
#include <string>
#include <unordered_map>
#include <IUpdatable.h>
#include <IDrawable.h>

class Component;
class Entity final
{
public: 
	Entity(const std::string& name) { this->name = name; }
	virtual ~Entity() = default;

	virtual void Start() {}
	virtual void Update(float dt);
	virtual void Draw();
	virtual void Destroy() {}

	template<class T> bool GetComponent(T** cmp)
	{
		const type_info* type = &typeid(**cmp);
		if (components.find(type) != components.end())
		{
			*cmp = components.find(type);
		}
	}

	template<class T> T* AddComponent() 
	{
		const type_info* type = &typeid(*cmp);
		components.insert(type, cmp);
	}

	std::string& GetName() { return name; }

private:
	std::string name;

	std::unordered_map<int, Component*> components;
	std::vector<IUpdatable*> updatables;
	std::vector<IDrawable*> drawables;
};