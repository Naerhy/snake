#ifndef SNAKE_H
#define SNAKE_H

#include <stdlib.h>
#include "raylib.h"
#include "libny.h"

#define BOARD_WIDTH (20 + 2)
#define BOARD_HEIGHT (15 + 2)
#define BLOCK_SIZE (32)
#define WINDOW_WIDTH (BOARD_WIDTH * BLOCK_SIZE)
#define WINDOW_HEIGHT (BOARD_HEIGHT * BLOCK_SIZE)

typedef enum e_screen
{
	TITLE_SCREEN,
	GAME_SCREEN
} t_screen;

typedef enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
} t_direction;

typedef enum e_movement
{
	WAITING,
	MOVED
} t_movement;

typedef struct s_coords
{
	int x;
	int y;
} t_coords;

typedef struct s_global
{
	t_ny_list* snake;
	t_screen screen;
	t_direction direction;
	t_movement movement;
	t_coords apple;
	int frames_counter;
} t_global;

// draw.c
void draw_window(t_global* g);
void draw_background(void);
void draw_snake(t_ny_list* snake);
void draw_apple(int x, int y);

// init.c
int init_game(t_global* g, t_ny_list** snake);
t_ny_list* create_bodypart(int x, int y);

// movement.c
void get_input_direction(t_global* g);
void move_snake(t_ny_list** snake, t_direction direction, t_coords* apple,
		t_screen* screen);
int check_apple_pos(t_coords* apple, t_ny_list* snake);
int check_death(int x, int y, t_ny_list* snake);

#endif
