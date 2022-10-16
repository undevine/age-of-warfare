#include "Application.h"

Application::Application()
{
	InitWindow(1280, 720, "Age of Warfare");
	SetTargetFPS(60);
}

Application::~Application()
{
	CloseWindow(); // Close application and OpenGL context
}

void Application::Update()
{
	while (!WindowShouldClose())
	{
		if (IsMouseButtonPressed(0))
		{
			soldiers.push_back(Soldier());
		}
		for (int i = 0; i < soldiers.size(); i++)
		{
			soldiers.at(i).position.x++;
		}
		Draw();
	}
}

void Application::Draw()
{
	BeginDrawing();
	ClearBackground(WHITE);
	for (int i = 0; i < soldiers.size(); i++)
	{
		DrawRectangle(soldiers.at(i).position.x, soldiers.at(i).position.y, soldiers.at(i).size.x, soldiers.at(i).size.y, GREEN);
	}
	EndDrawing();
}