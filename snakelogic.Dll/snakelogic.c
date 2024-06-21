#include "snakelogic.h"

void init_game(gamestate* state) {
    state->snake.length = 1;
    state->snake.body[0] = (point){ WIDTH / 2, HEIGHT / 2 };
    state->snake.dir = RIGHT;
    state->food.pos = (point){ rand() % WIDTH, rand() % HEIGHT };
    state->score = 0;
    state->game_over = 0;
}

void update_game(gamestate* state) {
    if (state->game_over) return;

    snake* snake = &state->snake;
    point next = snake->body[0];

    switch (snake->dir) {
    case UP: next.y--; break;
    case DOWN: next.y++; break;
    case LEFT: next.x--; break;
    case RIGHT: next.x++; break;
    }

    if (next.x < 0 || next.y < 0 || next.x >= WIDTH || next.y >= HEIGHT) {
        state->game_over = 1;
        return;
    }

    for (int i = 0; i < snake->length; i++) {
        if (snake->body[i].x == next.x && snake->body[i].y == next.y) {
            state->game_over = 1;
            return;
        }
    }

    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }

    snake->body[0] = next;

    if (next.x == state->food.pos.x && next.y == state->food.pos.y) {
        state->score++;
        snake->length++;
        state->food.pos = (point){ rand() % WIDTH, rand() % HEIGHT };
    }
}

void change_direction(gamestate* state, Direction new_dir) {
    if (state->snake.dir == UP && new_dir == DOWN) return;
    if (state->snake.dir == DOWN && new_dir == UP) return;
    if (state->snake.dir == LEFT && new_dir == RIGHT) return;
    if (state->snake.dir == RIGHT && new_dir == LEFT) return;
    state->snake.dir = new_dir;
}