#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include "level.h"

typedef struct Game
{
    char running;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    Level level;
} Game;

Game CreateGame();
void DrawGame(Game*);
void DestroyGame(Game*);

#endif // GAME_H