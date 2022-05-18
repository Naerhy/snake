#include "snake.h"

int main(void)
{
	t_ny_list* list;

	list = NULL;
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake");
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
