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

void move_snake(t_ny_list** snake, t_direction direction, t_coords* apple,
		t_screen* screen)
{
	t_coords head;
	t_ny_list* new_node;
	t_ny_list* last;

	head.x = ((t_coords*)(*snake)->content)->x;
	head.y = ((t_coords*)(*snake)->content)->y;
	if (direction == UP)
		head.y--;
	if (direction == DOWN)
		head.y++;
	if (direction == LEFT)
		head.x--;
	if (direction == RIGHT)
		head.x++;
	// if (!head_y || head_y == BOARD_HEIGHT - 1 || !head_x
			// || head_x == BOARD_WIDTH)
		// error
	new_node = create_bodypart(head.x, head.y);
	// check return value
	ny_list_prepend(snake, new_node);
	if (head.x == apple->x && head.y == apple->y)
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
	check_death(head.x, head.y, (*snake)->next, screen);
}

int check_apple_pos(t_coords* apple, t_ny_list* snake)
{
	while (snake)
	{
		if (apple->x == ((t_coords*)snake->content)->x
				&& apple->y == ((t_coords*)snake->content)->y)
			return (0);
		snake = snake->next;
	}
	return (1);
}

void check_death(int x, int y, t_ny_list* snake, t_screen* screen)
{
	if (!x || !y || x == BOARD_WIDTH - 1 || y == BOARD_HEIGHT - 1)
		*screen = TITLE_SCREEN;
	while (snake)
	{
		if (x == ((t_coords*)snake->content)->x
				&& y == ((t_coords*)snake->content)->y)
			*screen = TITLE_SCREEN;
		snake = snake->next;
	}
}
