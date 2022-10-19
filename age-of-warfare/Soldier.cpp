#include "Soldier.h"

Soldier::Soldier(bool _player)
{
	player = _player;
	if (player)
	{
		position = { 20.0f, 400.0f };
	}
	else
	{
		position = { 1200.0f, 400.0f };
	}
	size = { 50.0f, 100.0f };
	health = 100;
	damage = 50;
	alive = true;
}

Soldier::~Soldier()
{
}

void Soldier::CheckCollision(Soldier* s)
{
	Rectangle source = {
		position.x,
		position.y,
		size.x,
		size.y
	};

	Rectangle target = {
		s->position.x,
		s->position.y,
		s->position.x,
		s->position.y
	};

	if (health <= 0)
	{
		alive = false;
	}
	else
	{
		if (CheckCollisionRecs(source, target))
		{
			Attack(s);
		}
		else
		{
			MoveForward();
		}
	}
}

void Soldier::Attack(Soldier* s)
{
	s->TakeDamage(damage);
}

void Soldier::TakeDamage(int dmg)
{
	health -= dmg;
}

void Soldier::MoveForward()
{
	if (player)
	{
		this->position.x++;
	}
	else
	{
		this->position.x--;
	}
}

void Soldier::Draw()
{
	if (player)
	{
		DrawRectangle(position.x, position.y, size.x, size.y, GREEN);
	}
	else if (!alive)
	{
		DrawCircle(position.x, position.y + 100, 15, RED);
	}
	else
	{
		DrawRectangle(position.x, position.y, size.x, size.y, MAROON);
	}
}