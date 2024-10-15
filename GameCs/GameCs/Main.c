#include <stdio.h>
#include <SDL.h>
#include "boss.h"
#include "constants.h"
#include "../paddle.h"

// Variables globales para SDL
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

// Función para inicializar SDL
bool initialize_SDL(void) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error inicializando SDL: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Juego SDL POO", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Error creando ventana: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Error creando renderer: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

// Función para cerrar SDL
void close_SDL(void) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    if (!initialize_SDL()) {
        printf("Error inicializando SDL\n");
        return 1;
    }

    // Inicialización de Paddle y Boss
    Paddle paddle = create_paddle(50, WINDOW_HEIGHT - 70, 50, 30);
    Boss boss = create_boss(WINDOW_WIDTH - 100, 100, 100, 50);

    bool game_is_running = true;
    float gravity = 1000.0f;
    float delta_time = 0.0f;
    int last_frame_time = 0;

    // Bucle principal
    while (game_is_running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                game_is_running = false;
            }

            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_SPACE) {
                    paddle_jump(&paddle, -600.0f);
                }
            }
        }

        // Controlar el frame rate
        int time_to_wait = 16 - (SDL_GetTicks() - last_frame_time);
        if (time_to_wait > 0 && time_to_wait <= 16) {
            SDL_Delay(time_to_wait);
        }

        delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;
        last_frame_time = SDL_GetTicks();

        // Actualizar Paddle y Boss
        paddle_update(&paddle, delta_time, gravity);
        boss_update(&boss, delta_time);

        // Renderizar
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Renderizar Paddle
        SDL_Rect paddle_rect = { (int)paddle.x, (int)paddle.y, (int)paddle.width, (int)paddle.height };
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &paddle_rect); 

        // Renderizar Boss
        if (boss.active) {
            SDL_Rect boss_rect = { (int)boss.x, (int)boss.y, (int)boss.width, (int)boss.height };
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            SDL_RenderFillRect(renderer, &boss_rect);
        }

        SDL_RenderPresent(renderer);
    }

    close_SDL();
    return 0;
}
