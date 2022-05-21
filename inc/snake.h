#ifndef SNAKE_H
#define SNAKE_H

#include <stdlib.h>
#include "raylib.h"
#include "libny.h"

// delete after tests!!!
// delete after tests!!!
// delete after tests!!!
#include <stdio.h>

#define BOARD_WIDTH (20 + 2)
#define BOARD_HEIGHT (15 + 2)
#define BLOCK_SIZE (32)
#define WINDOW_WIDTH (BOARD_WIDTH * BLOCK_SIZE)
#define WINDOW_HEIGHT (BOARD_HEIGHT * BLOCK_SIZE)

typedef enum e_game_state
{
	TITLE_SCREEN,
	GAME_SCREEN
} t_game_state;

typedef enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
} t_direction;

typedef enum e_state
{
	WAITING,
	MOVED
} t_state;

typedef struct s_apple
{
	int x;
	int y;
} t_apple;

typedef struct s_global
{
	t_ny_list* snake;
	t_game_state game_state;
	int frames_counter;
	t_direction direction;
	t_state state;
	t_apple apple;
} t_global;

typedef struct s_bodypart
{
	int x;
	int y;
} t_bodypart;

// draw.c
void draw_background(void);
void draw_snake(t_ny_list* snake);
void draw_apple(int x, int y);

// game.c
void launch_game(t_global* g);

// init.c
int init_game(t_global* g, t_ny_list** snake);

// movement.c
void get_input_direction(t_global* g);
void move_snake(t_ny_list** snake, t_direction direction, t_apple* apple, t_game_state* game_state);
int check_apple_pos(t_apple* apple, t_ny_list* snake);
void check_death(int x, int y, t_ny_list* snake, t_game_state* game_state);

// snake.c
void free_bodypart(void* content);
t_bodypart* create_bodypart(int x, int y);

#endif
