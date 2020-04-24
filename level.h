#ifndef LEVEL_H
#define LEVEL_H

#include "car.h"
#include "player.h"

typedef struct {
    Car *cars;
    int cars_amount;
    Player player;
} Level;

Level CreateLevel(SDL_Renderer*);
void DrawLevel(SDL_Renderer*, Level*);
#endif // LEVEL_H