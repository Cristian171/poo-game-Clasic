#include "paddle.h"
#include <stdbool.h>
#include "GameCs/constants.h"
#include <SDL.h>


Paddle create_paddle(float x, float y, float width, float height) {
    Paddle paddle;
    paddle.base.x = x;
    paddle.base.y = y;
    paddle.base.width = width;
    paddle.base.height = height;
    paddle.base.vel_x = 0;
    paddle.base.vel_y = 0;
    paddle.is_jumping = false;
    return paddle;
}

void paddle_jump(Paddle* self, float jump_force) {
    if (!self->is_jumping) {
        self->base.vel_y = jump_force;
        self->is_jumping = true;
    }
}

void paddle_update(Paddle* self, float delta_time, float gravity) {
    game_object_update(&self->base, delta_time);  // Llama al método de la clase base
    self->base.vel_y += gravity * delta_time;

    if (self->base.y + self->base.height >= WINDOW_HEIGHT - 40) {
        self->base.y = WINDOW_HEIGHT - 40 - self->base.height;
        self->base.vel_y = 0;
        self->is_jumping = false;
    }
}

void paddle_render(Paddle* self, SDL_Renderer* renderer) {
    SDL_Rect rect = { (int)self->base.x, (int)self->base.y, (int)self->base.width, (int)self->base.height };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Color rojo
    SDL_RenderFillRect(renderer, &rect);
}
