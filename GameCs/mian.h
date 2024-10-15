#ifndef MAIN_H
#define MAIN_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdbool.h>
#include "main.h"
#include "paddle.h"
#include "boss.h"



// Dimensiones de la ventana
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

// Declaraciones de funciones globales
bool initialize_SDL(void);
void close_SDL(void);

#endif  // MAIN_H
