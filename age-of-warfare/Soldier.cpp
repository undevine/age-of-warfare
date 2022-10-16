#include "Soldier.h"

Soldier::Soldier()
{
	position = { 20.0f, 400.0f };
	size = { 50.0f, 100.0f };
	health = 100;
	damage = 50;
	alive = true;
}

Soldier::~Soldier()
{
}