#include "snake.h"

void free_bodypart(void* content)
{
	t_coords* bodypart;

	bodypart = (t_coords*)content;
	free(bodypart);
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

int main(void)
{
	t_global g;

	g.screen = TITLE_SCREEN;
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		draw_window(&g);
		g.frames_counter++;
	}
	CloseWindow();
	ny_list_clear(g.snake, free_bodypart);
	return (0);
}
