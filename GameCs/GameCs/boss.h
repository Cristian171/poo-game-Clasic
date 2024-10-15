#ifndef BOSS_H
#define BOSS_H

#include "gameobject.h"
#include <stdbool.h>

typedef struct Boss {
    GameObject base;  // Herencia: "base" es el GameObject de donde hereda el Boss
    int health;
    bool active;
} Boss;

// Declaración de métodos para Boss
Boss create_boss(float x, float y, float width, float height);
void boss_update(Boss* self, float delta_time);
void boss_render(Boss* self, SDL_Renderer* renderer);

#endif  // BOSS_H
