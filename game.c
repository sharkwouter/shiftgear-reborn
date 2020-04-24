#include "game.h"

void Game_Destroy(Game *game) {
    SDL_DestroyWindow(game->window);
}
