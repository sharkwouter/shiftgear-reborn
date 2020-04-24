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
        SDL_WINDOW_OPENGL
    );
    if (window == NULL) {
        SDL_Log("Could not initialize window: %s\n", SDL_GetError());
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL){
        SDL_Log("Could not initialize renderer: %s\n", SDL_GetError());
        exit(1);
    }

    Game game = {
        1,          // running
        window,     // *window
        renderer,   // *renderer
        NULL,       // *event
        CreateLevel(game.renderer)
    };

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
