#ifndef PADDLE_H
#define PADDLE_H
#include <stdbool.h>
#include "GameCs/gameobject.h"

typedef struct Paddle {
    GameObject base;  // Herencia: "base" es el GameObject de donde hereda el Paddle
    bool is_jumping;
} Paddle;

// Métodos específicos para Paddle
Paddle create_paddle(float x, float y, float width, float height);
void paddle_jump(Paddle* self, float jump_force);
void paddle_update(Paddle* self, float delta_time, float gravity);
void paddle_render(Paddle* self, SDL_Renderer* renderer);

#endif  // PADDLE_H
