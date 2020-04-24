#include "sprite.h"

Sprite CreateSpriteFromFile(SDL_Renderer* renderer, const char* location) {
    Sprite temp;

    SDL_Surface* surface = SDL_LoadBMP(location);
    if (surface == NULL) {
        SDL_Log("Unable to load image %s! SDL Error: %s\n", location, SDL_GetError());
        exit(1);
    }
    temp.texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (temp.texture == NULL) {
        SDL_Log("Unable to load texture for image %s! SDL Error: %s\n", location, SDL_GetError());
        exit(1);
    }

    SDL_QueryTexture(temp.texture, NULL, NULL, &temp.rect.w, &temp.rect.h);

    return temp;
}

void DrawSprite(SDL_Renderer* renderer, Sprite *sprite) {
    SDL_RenderCopy(renderer, sprite->texture, NULL, &sprite->rect);
}

void DestroySprite(Sprite* sprite) {
    SDL_DestroyTexture(sprite->texture);
}
