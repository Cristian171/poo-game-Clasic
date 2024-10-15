# Juego Clásico en C con SDL: Implementación de POO

Este es un proyecto de un **juego clásico** implementado en C utilizando la biblioteca SDL2 para gráficos, el cual sigue principios de **Programación Orientada a Objetos (POO)** Aunque C no soporta herencia de manera nativa, hemos usado **estructuras anidadas** para emular la herencia entre las clases de objetos en el juego.

## Descripción del Proyecto

El juego presenta un escenario con un **Paddle** que el jugador puede controlar y un **Boss** (jefe) que se mueve de manera horizontal. El objetivo del juego es interactuar con el Paddle y el Boss, implementando las físicas básicas como la gravedad y el movimiento del Paddle.

### Características del Juego

- **Paddle (Raqueta)**: El jugador puede hacer saltar el Paddle presionando la tecla `espacio`. El Paddle se mueve verticalmente y cae debido a la gravedad.
- **Boss (Jefe)**: El Boss se mueve de lado a lado en la pantalla. Tiene una cantidad de salud que disminuye a medida que interactúa con el Paddle. Cuando la salud llega a 0, el Boss deja de estar activo.
- **Gravedad**: El Paddle se ve afectado por la gravedad, lo que hace que caiga después de un salto.
- **Herencia Simulada en C**: Las propiedades comunes entre los objetos del juego se manejan mediante la estructura base `GameObject`, de la cual `Paddle` y `Boss` heredan.
- **Sistema de puntuacion** suma puntos al recolectar objetos y matar al jefe final con mensaje en consola.

## Estructura del Proyecto

### Archivos Principales

- **`GameObject.h` / `GameObject.c`**: Define la estructura base `GameObject` que contiene las propiedades comunes de los objetos (posición, tamaño, velocidad).
- **`Paddle.h` / `Paddle.c`**: Define la estructura `Paddle`, que hereda de `GameObject` y añade atributos específicos para el movimiento del Paddle (velocidad vertical, estado de salto).
- **`Boss.h` / `Boss.c`**: Define la estructura `Boss`, que hereda de `GameObject` y añade atributos específicos para el Boss (salud y estado activo).
- **`constants.h`**: Contiene las constantes globales para el juego (dimensiones de la ventana, FPS).
- **`main.c`**: El archivo principal donde se ejecuta el bucle del juego y se actualizan los objetos.

### Estructuras y Funciones

#### Diagrama UML
![UML Class Diagram](https://cdn.discordapp.com/attachments/762395755410620436/1295596955694796852/a1dd3d67-2c6d-447f-bb18-2525342f9d4c.webp?ex=670f3a31&is=670de8b1&hm=95b60051f4bed29dba358ede8169c67f455df863cfabf0404b15b6f0b3ba79fc&)


```c
typedef struct GameObject {
    float x, y;      // Posición en el eje X e Y
    float width, height; // Tamaño (ancho y alto)
    float vel_x;     // Velocidad en el eje X (para el movimiento)
} GameObject;

## Paddle (Estructura Derivada)

```c
typedef struct Paddle {
    GameObject base; // Contiene los atributos heredados de GameObject
    float vel_y;     // Velocidad en el eje Y (solo para el Paddle)
    bool is_jumping; // Estado si el Paddle está saltando
} Paddle;

typedef struct Boss {
    GameObject base; // Contiene los atributos heredados de GameObject
    int health;      // Salud específica del Boss
    bool active;     // Estado si el Boss está activo
} Boss;

## Funciones
- create_paddle(): Crea un nuevo Paddle y lo inicializa con sus valores por defecto.
- create_boss(): Crea un nuevo Boss y lo inicializa con sus valores por defecto.
- paddle_jump(): Hace que el Paddle salte si no está ya en el aire.
- paddle_update(): Actualiza la posición del Paddle teniendo en cuenta la gravedad.
- boss_update(): Actualiza la posición del Boss y cambia su dirección si toca los bordes de la pantalla.
- initialize_SDL(): Inicializa SDL2 y crea la ventana y el renderer.
- close_SDL(): Libera los recursos de SDL al cerrar el juego.

## Flujo del Juego

- Inicialización: El juego inicializa la ventana usando SDL y crea las instancias de Paddle y Boss.
Bucle del Juego:
- Se procesan los eventos (entrada del teclado para el salto del Paddle).
- Se actualizan las posiciones del Paddle y Boss según la física y el tiempo transcurrido (delta time).
- Se renderiza el Paddle y el Boss en la ventana.
- Colisiones: Aunque no se implementa una colisión directa en este código, se podría añadir la lógica para que el Paddle interactúe con el Boss.
- Cierre: Al cerrar la ventana, SDL libera los recursos.

## Dependencias
- SDL2
- SDLTTF
