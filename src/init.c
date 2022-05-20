#include "snake.h"

int init_global(t_global* g)
{
	g->snake = NULL;
	g->frames_counter = 0;
	g->direction = RIGHT;
	g->state = WAITING;
	return (1);
}

int init_snake(t_ny_list** snake)
{
	t_ny_list* new_node;
	t_bodypart* bodypart;

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
