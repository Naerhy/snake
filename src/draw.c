#include "snake.h"

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
	t_bodypart* bodypart;

	while (snake)
	{
		bodypart = snake->content;
		DrawRectangle(bodypart->x * BLOCK_SIZE, bodypart->y * BLOCK_SIZE,
				BLOCK_SIZE, BLOCK_SIZE, GREEN);
		snake = snake->next;
	}
}
