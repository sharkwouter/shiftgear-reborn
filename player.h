#ifndef PLAYER_H
#define PLAYER_H

#include "sprite.h"
#include "constants.h"

typedef struct Player {
    int lane;
    Sprite sprite;
} Player;

Player CreatePlayer(SDL_Renderer*);
void MovePlayer(Player*, int);
void DrawPlayer(SDL_Renderer*, Player*);
void DestroyPlayer(Player*);

#endif // PLAYER_H