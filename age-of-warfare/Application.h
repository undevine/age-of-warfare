#pragma once

#include <vector>
#include <raylib.h>
#include "Soldier.h"

class Application
{
public:
	Application();
	~Application();
	void Update();
private:
	void Draw();
	std::vector<Soldier> player_soldiers;
	std::vector<Soldier> cpu_soldiers;
};

