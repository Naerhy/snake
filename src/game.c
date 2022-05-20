#include "snake.h"

// change function name
void launch_game(t_global* g)
{
	BeginDrawing();
	draw_background();
	draw_snake(g->snake);
	draw_apple(g->apple.x, g->apple.y);
	EndDrawing();
	get_input_direction(g);
	if (g->frames_counter >= 15)
	{
		move_snake(&g->snake, g->direction, &g->apple);
		// check if snake has eaten apple
		// if so spawn new one and increases snake size
		g->state = WAITING;
		g->frames_counter = 0;
	}
}
