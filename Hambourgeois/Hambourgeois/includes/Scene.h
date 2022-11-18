#pragma once
#include <Entity.h>

class Scene : public hambourgeois::IScene{
public:
	virtual ~Scene() = default;
	virtual void Update(float dt) = 0;
	Entity* Instantiate(const std::string& name);
};