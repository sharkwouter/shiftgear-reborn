#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

typedef struct Game
{
    SDL_Window *window;
    SDL_Renderer *renderer;
} Game;

void Game_Destroy(Game *);

#endif