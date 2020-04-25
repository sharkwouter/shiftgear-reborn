#include "level.h"

Level CreateLevel(SDL_Renderer* renderer) {
    Level level;
    level.player = CreatePlayer(renderer);

    return level;
}

void DrawLevel(SDL_Renderer *renderer, Level *level) {
    DrawPlayer(renderer, &level->player);
}