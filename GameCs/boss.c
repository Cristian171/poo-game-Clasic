#include "boss.h"

Boss create_boss(float x, float y, float width, float height) {
    Boss boss;
    boss.x = x;
    boss.y = y;
    boss.width = width;
    boss.height = height;
    boss.vel_x = -100.0f;
    boss.health = 10;
    boss.active = true;
    return boss;
}

void boss_update(Boss* self, float delta_time) {
    self->x += self->vel_x * delta_time;
    if (self->x <= 0 || self->x + self->width >= WINDOW_WIDTH) {
        self->vel_x = -self->vel_x;
    }
    if (self->health <= 0) {
        self->active = false;
    }
}
