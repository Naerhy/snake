#include "snake.h"

int init_game(t_global* g, t_ny_list** snake)
{
	t_ny_list* new_node;
	t_bodypart* bodypart;

	g->snake = NULL;
	g->game_state = GAME_SCREEN;
	g->frames_counter = 0;
	g->direction = RIGHT;
	g->state = WAITING;
	g->apple.x = 5;
	g->apple.y = 5;
	for (int i = 0; i < 3; i++)
	{
		bodypart = create_bodypart(3 - i, 1);
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
