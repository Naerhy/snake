#include "snake.h"

void get_input_direction(t_global* g)
{
	if (g->movement == WAITING)
	{
		if (IsKeyDown(KEY_UP) && g->direction != DOWN)
		{
			g->direction = UP;
			g->movement = MOVED;
		}
		if (IsKeyDown(KEY_DOWN) && g->direction != UP)
		{
			g->direction = DOWN;
			g->movement = MOVED;
		}
		if (IsKeyDown(KEY_LEFT) && g->direction != RIGHT)
		{
			g->direction = LEFT;
			g->movement = MOVED;
		}
		if (IsKeyDown(KEY_RIGHT) && g->direction != LEFT)
		{
			g->direction = RIGHT;
			g->movement = MOVED;
		}
	}
}

void move_snake(t_ny_list** snake, t_direction direction, t_apple* apple,
		t_screen* screen)
{
	t_bodypart* bodypart;
	int head_x;
	int head_y;
	t_ny_list* new_node;
	t_ny_list* last;

	bodypart = (*snake)->content;
	head_x = bodypart->x;
	head_y = bodypart->y;
	if (direction == UP)
		head_y--;
	if (direction == DOWN)
		head_y++;
	if (direction == LEFT)
		head_x--;
	if (direction == RIGHT)
		head_x++;
	// if (!head_y || head_y == BOARD_HEIGHT - 1 || !head_x
			// || head_x == BOARD_WIDTH)
		// error
	new_node = create_bodypart(head_x, head_y);
	// check return value
	ny_list_prepend(snake, new_node);
	if (head_x == apple->x && head_y == apple->y)
	{
		while (1)
		{
			apple->x = GetRandomValue(1, BOARD_WIDTH - 2);
			apple->y = GetRandomValue(1, BOARD_HEIGHT - 2);
			if (check_apple_pos(apple, *snake))
				break;
		}
	}
	else
	{
		last = ny_list_last(*snake);
		ny_list_nth(*snake, ny_list_size(*snake) - 1)->next = NULL;
		ny_list_delete(last, free_bodypart);
	}
	check_death(head_x, head_y, (*snake)->next, screen);
}

int check_apple_pos(t_apple* apple, t_ny_list* snake)
{
	t_bodypart* bodypart;

	while (snake)
	{
		bodypart = snake->content;
		if (apple->x == bodypart->x && apple->y == bodypart->y)
			return (0);
		snake = snake->next;
	}
	return (1);
}

void check_death(int x, int y, t_ny_list* snake, t_screen* screen)
{
	t_bodypart* bodypart;

	if (!x || !y || x == BOARD_WIDTH - 1 || y == BOARD_HEIGHT - 1)
		*screen = TITLE_SCREEN;
	while (snake)
	{
		bodypart = snake->content;
		if (bodypart->x == x && bodypart->y == y)
			*screen = TITLE_SCREEN;
		snake = snake->next;
	}
}
