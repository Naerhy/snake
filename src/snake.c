#include "snake.h"

int main(void)
{
	t_global g;

	g.screen = TITLE_SCREEN;
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		draw_window(&g);
		g.frames_counter++;
	}
	CloseWindow();
	ny_list_clear(g.snake, free);
	return (0);
}
