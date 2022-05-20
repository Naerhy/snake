#include "snake.h"

// change function name
void launch_game(t_global* g)
{
	BeginDrawing();
	draw_background();
	draw_snake(g->snake);
	EndDrawing();
	get_input_direction(g);
	if (g->frames_counter >= 20)
	{
		move_snake(&g->snake, g->direction);
		// check if snake has eaten apple
		// if so spawn new one and increases snake size
		g->state = WAITING;
		g->frames_counter = 0;
	}
}
