#include "boss.h"
#include "constants.h"

Boss create_boss(float x, float y, float width, float height) {
    Boss boss;
    boss.base.x = x;          // Asignar la posición x desde base
    boss.base.y = y;          // Asignar la posición y desde base
    boss.base.width = width;  // Asignar el ancho desde base
    boss.base.height = height; // Asignar la altura desde base
    boss.base.vel_x = -100.0f;
    boss.health = 10;
    boss.active = true;
    return boss;
}

void boss_update(Boss* self, float delta_time) {
    game_object_update(&self->base, delta_time);  // Usar base para actualizar la posición

    // Cambiar la dirección de movimiento si toca los límites
    if (self->base.x <= 0 || self->base.x + self->base.width >= WINDOW_WIDTH) {
        self->base.vel_x = -self->base.vel_x;
    }

    // Si la salud llega a 0, el boss ya no es activo
    if (self->health <= 0) {
        self->active = false;
    }
}

void boss_render(Boss* self, SDL_Renderer* renderer) {
    SDL_Rect rect = { (int)self->base.x, (int)self->base.y, (int)self->base.width, (int)self->base.height };
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);  // Color amarillo
    SDL_RenderFillRect(renderer, &rect);
}
