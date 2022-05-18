#include "raylib.h"
#include "snake.h"

int main(void)
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "My Snake");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		EndDrawing();
	}
	CloseWindow();
	return (0);
}
