#pragma once
#include <raylib.h>

class Soldier
{
public:
	Soldier();
	~Soldier();
	Vector2 position;
	Vector2 size;
	int health;
	int damage;
	bool alive;
};

