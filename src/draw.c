#include "snake.h"

void draw_window(t_global* g)
{
	if (g->screen == GAME_SCREEN)
	{
		BeginDrawing();
		draw_background();
		draw_snake(g->snake);
		draw_apple(g->apple.x, g->apple.y);
		EndDrawing();
		get_input_direction(g);
		if (g->frames_counter >= 15)
		{
			move_snake(&g->snake, g->direction, &g->apple, &g->screen);
			g->movement = WAITING;
			g->frames_counter = 0;
		}
	}
	else
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("PRESS ENTER TO BEGIN A NEW GAME", 150,
				WINDOW_HEIGHT / 2, 20, YELLOW);
		EndDrawing();
		if (IsKeyDown(KEY_ENTER))
			init_game(g, &g->snake);
	}
}

void draw_background(void)
{
	Color color;

	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		for (int x = 0; x < BOARD_WIDTH; x++)
		{
			if (!y || !x || y == BOARD_HEIGHT - 1 || x == BOARD_WIDTH - 1)
				color = YELLOW;
			else
				color = BLACK;
			DrawRectangle(x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE,
					BLOCK_SIZE, color);
		}
	}
}

void draw_snake(t_ny_list* snake)
{
	t_coords* bodypart;

	while (snake)
	{
		bodypart = snake->content;
		DrawRectangle(bodypart->x * BLOCK_SIZE, bodypart->y * BLOCK_SIZE,
				BLOCK_SIZE, BLOCK_SIZE, GREEN);
		snake = snake->next;
	}
}

void draw_apple(int x, int y)
{
	DrawRectangle(x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE,
			BLOCK_SIZE, RED);
}
