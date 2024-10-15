#ifndef BOSS_H
#define BOSS_H

typedef struct Boss {
    float x, y;
    float width, height;
    float vel_x;
    int health;
    bool active;
} Boss;

// Declaración de métodos para Boss
Boss create_boss(float x, float y, float width, float height);
void boss_update(Boss* self, float delta_time);

#endif  // BOSS_H
