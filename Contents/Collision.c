/**
    Collision.c

    @author Kristoffer Alquiza
*/

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "header.h"

bool collide_player_to_block(Player p, Block b, int x, int y) {
    if (((p.posX + x + 12) < (b.posX + b.sizeX)) &&
        ((p.posX + p.sizeX + x + 12) > b.posX) &&
        ((p.posY + y) < (b.posY + b.sizeY)) &&
        ((p.sizeY + p.posY + y) > b.posY)) { return true; }
    return false;
}

bool collide_player_to_level(Player p, Block l[][level_size], int x, int y) {
    for (int i = 0; i < level_size; i++) {
        for (int j = 0; j < level_size; j++) {
            if (l[i][j].active) {
                if (collide_player_to_block(p, l[i][j], x, y)) return true;
            }
        }
    }
    return false;
}

bool collide_projectile_to_block(Projectile p, Block b, int x, int y) {
    if (((p.posX + x) < (b.posX + b.sizeX)) &&
        ((p.posX + p.sizeX + x) > b.posX) &&
        ((p.posY + y) < (b.posY + b.sizeY)) &&
        ((p.sizeY + p.posY + y) > b.posY)) { return true; }
    return false;
}

/*^--------------------------------------------------------------------------------*/

bool level_check(Block l[][level_size]) {
    for (int i = 0; i < level_size; i++) {
        for (int j = 0; j < level_size; j++) {
            if (l[i][j].active) return false;
        }
    }
    return true;
}
