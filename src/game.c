#include "snake.h"

// change function name
void launch_game(t_global* g)
{
	if (g->game_state == GAME_SCREEN)
	{
		BeginDrawing();
		draw_background();
		draw_snake(g->snake);
		draw_apple(g->apple.x, g->apple.y);
		EndDrawing();
		get_input_direction(g);
		if (g->frames_counter >= 15)
		{
			move_snake(&g->snake, g->direction, &g->apple, &g->game_state);
			g->state = WAITING;
			g->frames_counter = 0;
		}
	}
	else
	{
		g->frames_counter = 0;
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("PRESS ENTER TO BEGIN A NEW GAME", 150,
				WINDOW_HEIGHT / 2, 20, YELLOW);
		EndDrawing();
		if (IsKeyDown(KEY_ENTER))
			g->game_state = GAME_SCREEN;
	}
}
