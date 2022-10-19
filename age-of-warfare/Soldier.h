#pragma once
#include <raylib.h>

class Soldier
{
public:
	Soldier(bool _player);
	~Soldier();
	void CheckCollision(Soldier* s);
	void MoveForward();
	void TakeDamage(int dmg);
	void Draw();
	bool alive;
private:
	void Attack(Soldier* s);
	Vector2 position;
	Vector2 size;
	int health;
	int damage;
	bool player;
};

