#include <SDL2/SDL.h>
#include <stdio.h>
#include "game.h"

#ifdef PSP
#include "psp.h"
PSP_MODULE_INFO("Shiftgear", 0, 1, 1);
SetupPSPCallbacks();
#endif

Game game;

int init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Could not initialize SDL2: %s\n", SDL_GetError());
        return 1;
    }
    game = CreateGame();
    return 0;
}

void handleEvents() {
    while (SDL_PollEvent(&game.event)) {
        if (game.event.type == SDL_QUIT) {
            game.running = 0;
        } else if (game.event.type == SDL_KEYDOWN) {
            switch(game.event.key.keysym.sym) {
            case SDLK_w:
            case SDLK_a:
            case SDLK_UP:
            case SDLK_LEFT:
                MovePlayer(&game.level.player, -1);
                break;
            case SDLK_s:
            case SDLK_d:
            case SDLK_DOWN:
            case SDLK_RIGHT:
                MovePlayer(&game.level.player, 1);
                break;
            }
        }
    }
}

int quit() {
    DestroyGame(&game);
    SDL_Quit();
    return 0;
}

int main() {
    if (init() != 0) {
        quit();
        return 1;
    }

	while (game.running) {
		handleEvents();
        // game update here
		DrawGame(&game);
		SDL_Delay(1000/60);
	}

    return quit();
}
