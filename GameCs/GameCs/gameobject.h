#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>

typedef struct GameObject {
    float x, y;
    float width, height;
    float vel_x, vel_y;
} GameObject;

// Métodos comunes para todos los GameObjects
void game_object_update(GameObject* self, float delta_time);
void game_object_render(GameObject* self, SDL_Renderer* renderer);

#endif  // GAMEOBJECT_H
