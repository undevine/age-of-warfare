#include "Application.h"

Application::Application()
{
	InitWindow(1280, 720, "Age of Warfare");
	SetTargetFPS(60);
}

Application::~Application()
{
	CloseWindow();
}

void Application::Update()
{
	while (!WindowShouldClose())
	{
		if (IsMouseButtonPressed(0))
		{
			player_soldiers.push_back(Soldier(true));
		}
		if (IsMouseButtonPressed(1))
		{
			cpu_soldiers.push_back(Soldier(false));
		}
		for (int i = 0; i < player_soldiers.size(); i++)
		{
			if (cpu_soldiers.size() > 0)
			{
				player_soldiers.at(i).CheckCollision(&cpu_soldiers.front());
			}
			else
			{
				player_soldiers.at(i).MoveForward();
			}
		}
		for (int i = 0; i < cpu_soldiers.size(); i++)
		{
			if (player_soldiers.size() > 0)
			{
				cpu_soldiers.at(i).CheckCollision(&player_soldiers.front());
			}
			else
			{
				cpu_soldiers.at(i).MoveForward();
			}
		}
		Draw();
	}
}

void Application::Draw()
{
	BeginDrawing();
	ClearBackground(WHITE);
	for (int i = 0; i < player_soldiers.size(); i++)
	{
		player_soldiers.at(i).Draw();
	}
	for (int i = 0; i < cpu_soldiers.size(); i++)
	{
		cpu_soldiers.at(i).Draw();
	}
	EndDrawing();
}