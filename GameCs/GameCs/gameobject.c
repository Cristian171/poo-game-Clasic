#include "gameobject.h"
#include <SDL.h>

// Actualiza la posición del GameObject según su velocidad y el tiempo transcurrido
void game_object_update(GameObject* self, float delta_time) {
    self->x += self->vel_x * delta_time;
    self->y += self->vel_y * delta_time;
}

// Renderiza el GameObject usando SDL_Renderer
void game_object_render(GameObject* self, SDL_Renderer* renderer) {
    SDL_Rect rect = { (int)self->x, (int)self->y, (int)self->width, (int)self->height };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Color blanco
    SDL_RenderFillRect(renderer, &rect);
}
