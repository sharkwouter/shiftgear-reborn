#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <stdlib.h>

typedef struct Sprite {
    SDL_Rect rect;
    SDL_Texture* texture;
} Sprite;

Sprite CreateSpriteFromFile(SDL_Renderer*, const char*);
void DrawSprite(SDL_Renderer*, Sprite*);
void DestroySprite(Sprite*);

#endif // SPRITE_H