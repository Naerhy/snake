#ifndef SNAKE_H
#define SNAKE_H

#include <stdlib.h>
#include "raylib.h"
#include "libny.h"

#define BOARD_WIDTH (20)
#define BOARD_HEIGHT (15)
#define BLOCK_SIZE (32)
#define WINDOW_WIDTH (BOARD_WIDTH * BLOCK_SIZE)
#define WINDOW_HEIGHT (BOARD_HEIGHT * BLOCK_SIZE)

typedef struct s_bodypart
{
	int x;
	int y;
} t_bodypart;

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

#endif
