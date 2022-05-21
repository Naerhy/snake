// gcc -Iinc src/snake.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 lib/libny.a

#include "snake.h"

void free_bodypart(void* content)
{
	t_bodypart* to_free;

	to_free = (t_bodypart*)content;
	free(to_free);
}

t_bodypart* create_bodypart(int x, int y)
{
	t_bodypart* new;

	new = calloc(1, sizeof(t_bodypart));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	return (new);
}

// only draw every x frames, not every frame??
int main(void)
{
	t_global g;

	init_global(&g);
	if (!init_snake(&g.snake))
	{
		ny_list_clear(g.snake, free_bodypart);
		return (1);
	}
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		launch_game(&g);
		g.frames_counter++;
	}
	CloseWindow();
	ny_list_clear(g.snake, free_bodypart);
	return (0);
}
