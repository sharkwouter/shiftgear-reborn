#include "player.h"

#define PLAYER_X 8

// This function uses the player's lane and the lane constants
void setPlayerY(Player* player) {
    player->sprite.rect.y = ((player->lane-1) * LANE_WIDTH) + LANE_OFFSET;
}

Player CreatePlayer(SDL_Renderer* renderer) {
    Player player;
    player.lane = 2;
    player.sprite = CreateSpriteFromFile(renderer, IMAGE_PLAYER);
    player.sprite.rect.x = LANE_OFFSET;
    setPlayerY(&player);

    player.sprite.rect.h = LANE_WIDTH;
    
    return player;
}

void MovePlayer(Player* player, int movement) {
    int new_location = player->lane + movement;
    if (0 < new_location && new_location <= LANES) {
        player->lane = new_location;
        setPlayerY(player);
    }
}

void DrawPlayer(SDL_Renderer* renderer, Player* player) {
    DrawSprite(renderer, &player->sprite);
}

void DestroyPlayer(Player* player) {
    DestroySprite(&player->sprite);
}
