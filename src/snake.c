// gcc -Iinc src/snake.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 lib/libny.a

#include "snake.h"

void free_bodypart(void* content)
{
	t_bodypart* to_free;

	to_free = (t_bodypart*)content;
	free(content);
}

t_bodypart* create_bodypart(int x, int y)
{
	t_bodypart *new;

	new = calloc(1, sizeof(t_bodypart));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	return (new);
}

int init_snake(t_ny_list** snake)
{
	t_ny_list* new_node;
	t_bodypart* bodypart;

	*snake = NULL;
	for (int i = 0; i < 3; i++)
	{
		bodypart = create_bodypart(2 - i, 0);
		if (!bodypart)
			return (0);
		new_node = ny_list_new(bodypart);
		if (!new_node)
		{
			free(bodypart);
			return (0);
		}
		ny_list_append(snake, new_node);
	}
	return (1);
}

int main(void)
{
	t_ny_list* snake;

	if (!init_snake(&snake))
	{
		ny_list_clear(snake, free_bodypart);
		return (1);
	}
	// set snake default direction
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);
		
		EndDrawing();
	}
	CloseWindow();
	ny_list_clear(snake, free_bodypart);
	return (0);
}
