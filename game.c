#include "game.h"

Game CreateGame() {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    window = SDL_CreateWindow(
        GAME_NAME,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        0
    );
    if (window == NULL) {
        SDL_Log("Could not initialize window: %s\n", SDL_GetError());
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL){
        SDL_Log("Could not initialize renderer: %s\n", SDL_GetError());
        exit(1);
    }

    Game game;
    game.running = 1;
    game.window = window;
    game.renderer = renderer;
    game.level = CreateLevel(game.renderer);

    return game;
}

void DrawGame(Game *game) {
    SDL_RenderClear(game->renderer);
    DrawLevel(game->renderer, &game->level);
    SDL_RenderPresent(game->renderer);
}

void DestroyGame(Game *game) {
    SDL_DestroyWindow(game->window);
    SDL_DestroyRenderer(game->renderer);
}
