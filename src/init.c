#include "snake.h"

int init_game(t_global* g, t_ny_list** snake)
{
	t_ny_list* new_node;

	g->snake = NULL;
	g->screen = GAME_SCREEN;
	g->direction = RIGHT;
	g->movement = WAITING;
	g->apple.x = 5;
	g->apple.y = 5;
	g->frames_counter = 0;
	for (int i = 0; i < 3; i++)
	{
		new_node = create_bodypart(3 - i, 1);
		if (!new_node)
			return (0);
		ny_list_append(snake, new_node);
	}
	return (1);
}

t_ny_list* create_bodypart(int x, int y)
{
	t_coords* bodypart;
	t_ny_list* new_node;

	bodypart = calloc(1, sizeof(t_coords));
	if (!bodypart)
		return (NULL);
	bodypart->x = x;
	bodypart->y = y;
	new_node = ny_list_new(bodypart);
	if (!new_node)
	{
		free(bodypart);
		return (NULL);
	}
	return (new_node);
}
