#pragma once
#include <string>

class Entity
{
public: 
	virtual ~Entity() = default;

	virtual void Start() {};
	virtual void Update(float dt) {};
	virtual void Draw() {};
	virtual void Destroy() {};

	std::string& GetName() { return name; }

private:
	std::string name;
};