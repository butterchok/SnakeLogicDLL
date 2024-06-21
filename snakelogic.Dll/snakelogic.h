#pragma once

#pragma once

#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

typedef enum { UP, DOWN, LEFT, RIGHT } Direction;

typedef struct point {
    int x, y;
} point;

typedef struct snake {
    point body[WIDTH * HEIGHT];
    int length;
    Direction dir;
} snake;

typedef struct food {
    point pos;
}food;

typedef struct gamestate {
    snake snake;
    food food;
    int score;
    int game_over;
} gamestate;

void init_game(gamestate* state);
void update_game(gamestate* state);
void change_direction(gamestate* state, Direction new_dir);