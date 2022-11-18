#pragma once
#include <Engine.h>
#include <Scene.h>
#include <iostream>

class Level1 : public Scene {
public:
	virtual void Load();
	virtual void Update(float dt);
};