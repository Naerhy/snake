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

void move_snake(t_ny_list** snake, t_direction dir)
{
	t_bodypart* bodypart;
	int head_x;
	int head_y;
	t_ny_list* new_node;
	t_ny_list* last;

	bodypart = (*snake)->content;
	head_x = bodypart->x;
	head_y = bodypart->y;
	if (dir == UP)
		head_y--;
	if (dir == DOWN)
		head_y++;
	if (dir == LEFT)
		head_x--;
	if (dir == RIGHT)
		head_x++;
	bodypart = create_bodypart(head_x, head_y);
	// check return
	new_node = ny_list_new(bodypart);
	// check return
	ny_list_prepend(snake, new_node);
	last = ny_list_last(*snake);
	ny_list_nth(*snake, ny_list_size(*snake) - 1)->next = NULL;
	ny_list_delete(last, free_bodypart);
}

void draw_snake(t_ny_list* snake)
{
	t_bodypart* bodypart;

	while (snake)
	{
		bodypart = snake->content;
		DrawRectangle(bodypart->x * BLOCK_SIZE, bodypart->y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, YELLOW);
		snake = snake->next;
	}
}

t_direction get_input_direction(t_direction old_dir, t_state* state)
{
	t_direction new_dir;

	if (*state == MOVED)
		return (old_dir);
	new_dir = old_dir;
	// add state condition => only if state == WAITING??
	if (IsKeyDown(KEY_UP) && old_dir != DOWN)
	{
		new_dir = UP;
		*state = MOVED;
	}
	if (IsKeyDown(KEY_DOWN) && old_dir != UP)
	{
		new_dir = DOWN;
		*state = MOVED;
	}
	if (IsKeyDown(KEY_LEFT) && old_dir != RIGHT)
	{
		new_dir = LEFT;
		*state = MOVED;
	}
	if (IsKeyDown(KEY_RIGHT) && old_dir != LEFT)
	{
		new_dir = RIGHT;
		*state = MOVED;
	}
	return (new_dir);
}

int main(void)
{
	t_ny_list* snake;
	int frames_counter;
	t_direction dir;
	t_state state;

	if (!init_snake(&snake))
	{
		ny_list_clear(snake, free_bodypart);
		return (1);
	}
	frames_counter = 0;
	dir = RIGHT;
	state = WAITING;
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		frames_counter++;
		if (frames_counter >= 20)
		{
			move_snake(&snake, dir);
			frames_counter = 0;
			state = WAITING;
		}
		dir = get_input_direction(dir, &state);

		BeginDrawing();
		ClearBackground(BLACK);
		draw_snake(snake);
		EndDrawing();
	}
	CloseWindow();
	ny_list_clear(snake, free_bodypart);
	return (0);
}
