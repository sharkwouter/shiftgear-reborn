#include <SDL2/SDL.h>
#include "game.h"

#define GAME_NAME "shiftgear"
#define WINDOW_WIDTH 480
#define WINDOW_HEIGHT 272

Game game = {
    NULL, // Window pointer
    NULL  // Renderer pointer
};

int init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log(SDL_LOG_PRIORITY_ERROR, "Could not initialize SDL2: %s\n", SDL_GetError(), );
        return 1;
    }

    game.window = SDL_CreateWindow(
        GAME_NAME,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_OPENGL
    );
    if (game.window == NULL) {
        SDL_Log("Could not initialize window: %s\n", SDL_GetError(), SDL_LOG_PRIORITY_ERROR);
        return 1;
    }
    return 0;
}

int quit() {
    Game_Destroy(&game);
    SDL_Quit();
    return 0;
}

int main() {
    if (init() != 0) {
        quit();
        return 1;
    }
    
    SDL_Delay(3000);

    return quit();
}
