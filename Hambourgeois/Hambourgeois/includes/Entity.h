#pragma once

#include <map>
#include <vector>

#include <IUpdatable.h>
#include <IDrawable.h>
#include <Engine.h>
#include <Component.h>

class Entity final
{
public: 
	Entity(const std::string& name) { this->name = name; }
	virtual ~Entity() = default;

	float x() { return transform[0]; };
	float y() { return transform[1]; };
	float w() { return transform[2]; };
	float h() { return transform[3]; };

	void Set_X(float x) { transform[0] = x; }
	void Set_Y(float y) { transform[1] = y; }
	void Set_W(float w) { transform[2] = w; }
	void Set_H(float h) { transform[3] = h; }

	void Start() {}
	virtual void Update(float dt);
	virtual void Draw();
	void Destroy();

	template<class T> bool GetComponent(T** cmp)
	{
		const type_info* type = &typeid(**cmp);
		if (components.find(type) != components.end())
		{
			*cmp = components.find(type);
		}
	}

	template<typename T> T* AddComponent()
	{
		T* cmp = new T(this);
		const type_info* type = &typeid(*cmp);
		if (components.count(type) == 0)
		{
			auto temp = dynamic_cast<IDrawable*>(cmp);
			if (temp != nullptr)
			{
				drawables.push_back(temp);
			}

			auto temp2 = dynamic_cast<IUpdatable*>(cmp);
			if (temp2 != nullptr)
			{
				updatables.push_back(temp2);
			}

			components.emplace(type, cmp);
		}

		return cmp;
	}

	std::string& GetName() { return name; }

private:
	float transform[4];
	std::string name;

	std::map<const type_info*, Component*> components;
	std::vector<IUpdatable*> updatables;
	std::vector<IDrawable*> drawables;
};