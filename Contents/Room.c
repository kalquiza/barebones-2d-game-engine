/**
    Room.c

    @author Kristoffer Alquiza
*/

#include <stdio.h>
#include "header.h"
#include "DrawUtils.h"
#include "AnimUtils.h"

// pacman
void level_1(Block l[][level_size]){
    l[5][1] = yellow;
    l[6][1] = yellow;
    l[7][1] = yellow;
    l[8][1] = yellow;
    l[9][1] = yellow;

    l[3][2] = yellow;
    l[4][2] = yellow;
    l[5][2] = yellow;
    l[6][2] = yellow;
    l[7][2] = yellow;
    l[8][2] = yellow;
    l[9][2] = yellow;
    l[10][2] = yellow;
    l[11][2] = yellow;

    l[2][3] = yellow;
    l[3][3] = yellow;
    l[4][3] = yellow;
    l[5][3] = yellow;
    l[6][3] = yellow;
    l[7][3] = yellow;
    l[8][3] = yellow;
    l[9][3] = yellow;
    l[10][3] = yellow;
    l[11][3] = yellow;
    l[12][3] = yellow;

    l[2][4] = yellow;
    l[3][4] = yellow;
    l[4][4] = yellow;
    l[5][4] = yellow;
    l[6][4] = yellow;
    l[7][4] = yellow;
    l[8][4] = yellow;
    l[9][4] = yellow;
    l[10][4] = yellow;
    l[11][4] = yellow;
    l[12][4] = yellow;

    l[1][5] = yellow;
    l[2][5] = yellow;
    l[3][5] = yellow;
    l[4][5] = yellow;
    l[5][5] = yellow;
    l[6][5] = yellow;
    l[7][5] = yellow;
    l[8][5] = yellow;
    l[9][5] = yellow;
    l[10][5] = yellow;

    l[1][6] = yellow;
    l[2][6] = yellow;
    l[3][6] = yellow;
    l[4][6] = yellow;
    l[5][6] = yellow;
    l[6][6] = yellow;
    l[7][6] = yellow;

    l[1][7] = yellow;
    l[2][7] = yellow;
    l[3][7] = yellow;
    l[4][7] = yellow;
    l[9][7] = green;
    l[11][7] = blue;
    l[13][7] = red;

    l[1][8] = yellow;
    l[2][8] = yellow;
    l[3][8] = yellow;
    l[4][8] = yellow;
    l[5][8] = yellow;
    l[6][8] = yellow;
    l[7][8] = yellow;

    l[1][9] = yellow;
    l[2][9] = yellow;
    l[3][9] = yellow;
    l[4][9] = yellow;
    l[5][9] = yellow;
    l[6][9] = yellow;
    l[7][9] = yellow;
    l[8][9] = yellow;
    l[9][9] = yellow;
    l[10][9] = yellow;

    l[2][10] = yellow;
    l[3][10] = yellow;
    l[4][10] = yellow;
    l[5][10] = yellow;
    l[6][10] = yellow;
    l[7][10] = yellow;
    l[8][10] = yellow;
    l[9][10] = yellow;
    l[10][10] = yellow;
    l[11][10] = yellow;
    l[12][10] = yellow;

    l[2][11] = yellow;
    l[3][11] = yellow;
    l[4][11] = yellow;
    l[5][11] = yellow;
    l[6][11] = yellow;
    l[7][11] = yellow;
    l[8][11] = yellow;
    l[9][11] = yellow;
    l[10][11] = yellow;
    l[11][11] = yellow;
    l[12][11] = yellow;

    l[3][12] = yellow;
    l[4][12] = yellow;
    l[5][12] = yellow;
    l[6][12] = yellow;
    l[7][12] = yellow;
    l[8][12] = yellow;
    l[9][12] = yellow;
    l[10][12] = yellow;
    l[11][12] = yellow;

    l[5][13] = yellow;
    l[6][13] = yellow;
    l[7][13] = yellow;
    l[8][13] = yellow;
    l[9][13] = yellow;
}

// space invaders
void level_2(Block l[][level_size]) {
    l[4][0] = blue;
    l[10][0] = blue;

    l[5][1] = blue;
    l[9][1] = blue;

    l[4][2] = blue;
    l[5][2] = blue;
    l[6][2] = blue;
    l[7][2] = blue;
    l[8][2] = blue;
    l[9][2] = blue;
    l[10][2] = blue;

    l[3][3] = blue;
    l[4][3] = blue;
    l[6][3] = blue;
    l[7][3] = blue;
    l[8][3] = blue;
    l[10][3] = blue;
    l[11][3] = blue;

    l[3][4] = blue;
    l[4][4] = blue;
    l[5][4] = blue;
    l[6][4] = blue;
    l[7][4] = blue;
    l[8][4] = blue;
    l[9][4] = blue;
    l[10][4] = blue;
    l[11][4] = blue;
    l[12][4] = blue;

    l[2][4] = blue;
    l[3][4] = blue;
    l[5][4] = blue;
    l[6][4] = blue;
    l[7][4] = blue;
    l[8][4] = blue;
    l[9][4] = blue;
    l[10][4] = blue;
    l[12][4] = blue;

    l[2][5] = blue;
    l[4][5] = blue;
    l[5][5] = blue;
    l[6][5] = blue;
    l[7][5] = blue;
    l[8][5] = blue;
    l[9][5] = blue;
    l[10][5] = blue;
    l[12][5] = blue;

    l[0][6] = green;
    l[2][6] = blue;
    l[4][6] = blue;
    l[10][6] = blue;
    l[12][6] = blue;
    l[14][6] = green;

    l[1][7] = green;
    l[5][7] = blue;
    l[6][7] = blue;
    l[8][7] = blue;
    l[9][7] = blue;
    l[13][7] = green;

    l[2][8] = green;
    l[5][8] = red;
    l[12][8] = green;

    l[1][9] = green;
    l[10][9] = red;
    l[13][9] = green;

    l[0][10] = green;
    l[5][10] = red;
    l[7][10] = red;
    l[9][10] = red;
    l[14][10] = green;

    l[1][11] = green;
    l[2][11] = red;
    l[4][11] = red;
    l[13][11] = green;

    l[2][12] = green;
    l[6][12] = red;
    l[7][12] = red;
    l[9][12] = red;
    l[10][12] = red;
    l[12][12] = green;

    l[0][13] = red;
    l[4][13] = red;
    l[6][13] = red;
    l[7][13] = red;
    l[9][13] = red;
    l[11][13] = red;

    l[2][14] = red;
    l[3][14] = red;
    l[4][14] = yellow;
    l[5][14] = red;
    l[6][14] = yellow;
    l[7][14] = yellow;
    l[8][14] = red;
    l[9][14] = red;
    l[12][14] = red;

    l[1][15] = red;
    l[2][15] = yellow;
    l[3][15] = yellow;
    l[4][15] = yellow;
    l[5][15] = yellow;
    l[6][15] = yellow;
    l[7][15] = yellow;
    l[8][15] = yellow;
    l[9][15] = yellow;
    l[10][15] = red;
    l[12][15] = red;
    l[14][15] = red;
}

// q-bert
void level_3(Block l[][level_size]) {
    l[10][0] = yellow;
    l[11][0] = yellow;
    l[12][0] = yellow;
    l[13][0] = yellow;
    l[14][0] = yellow;

    l[9][1] = yellow;
    l[10][1] = yellow;
    l[11][1] = yellow;
    l[12][1] = blue;
    l[13][1] = blue;
    l[14][1] = yellow;

    l[8][2] = yellow;
    l[9][2] = yellow;
    l[10][2] = yellow;
    l[11][2] = blue;
    l[12][2] = blue;
    l[13][2] = yellow;
    l[14][2] = yellow;

    l[8][3] = yellow;
    l[9][3] = yellow;
    l[10][3] = yellow;
    l[11][3] = yellow;
    l[12][3] = yellow;
    l[13][3] = yellow;
    l[14][3] = yellow;

    l[2][4] = red;
    l[3][4] = red;
    l[4][4] = red;
    l[5][4] = red;
    l[6][4] = red;
    l[8][4] = yellow;
    l[9][4] = yellow;
    l[10][4] = yellow;
    l[11][4] = blue;
    l[12][4] = yellow;
    l[13][4] = yellow;
    l[14][4] = yellow;

    l[1][5] = red;
    l[2][5] = red;
    l[3][5] = red;
    l[4][5] = yellow;
    l[5][5] = red;
    l[6][5] = yellow;
    l[7][5] = red;
    l[9][5] = yellow;
    l[10][5] = yellow;
    l[11][5] = yellow;
    l[12][5] = yellow;
    l[13][5] = yellow;

    l[1][6] = red;
    l[2][6] = red;
    l[3][6] = red;
    l[4][6] = blue;
    l[5][6] = red;
    l[6][6] = blue;
    l[7][6] = red;
    l[9][6] = yellow;

    l[1][7] = red;
    l[2][7] = red;
    l[3][7] = red;
    l[4][7] = blue;
    l[5][7] = red;
    l[6][7] = blue;
    l[7][7] = red;
    l[8][7] = red;

    l[1][8] = red;
    l[2][8] = red;
    l[3][8] = red;
    l[4][8] = red;
    l[5][8] = red;
    l[6][8] = red;
    l[7][8] = red;
    l[8][8] = red;
    l[9][8] = red;
    l[10][8] = red;

    l[1][9] = red;
    l[2][9] = red;
    l[3][9] = red;
    l[4][9] = red;
    l[5][9] = red;
    l[6][9] = red;
    l[7][9] = red;
    l[8][9] = red;
    l[9][9] = blue;
    l[10][9] = blue;
    l[11][9] = red;

    l[2][10] = red;
    l[3][10] = green;
    l[4][10] = green;
    l[5][10] = red;
    l[9][10] = red;
    l[10][10] = red;

    l[1][11] = green;
    l[2][11] = red;
    l[3][11] = green;
    l[4][11] = green;
    l[5][11] = red;
    l[6][11] = green;

    l[0][12] = green;
    l[1][12] = green;
    l[2][12] = red;
    l[3][12] = red;
    l[4][12] = green;
    l[5][12] = red;
    l[6][12] = red;
    l[7][12] = green;
    l[8][12] = green;

    l[0][13] = green;
    l[1][13] = green;
    l[2][13] = green;
    l[3][13] = green;
    l[4][13] = green;
    l[5][13] = green;
    l[6][13] = green;
    l[7][13] = green;
    l[8][13] = green;
    l[9][13] = green;
    l[10][13] = green;

    l[0][14] = green;
    l[1][14] = green;
    l[2][14] = green;
    l[3][14] = green;
    l[4][14] = green;
    l[5][14] = green;
    l[6][14] = green;
    l[7][14] = green;
    l[8][14] = green;
    l[9][14] = yellow;
    l[10][14] = yellow;

    l[0][15] = green;
    l[1][15] = green;
    l[2][15] = green;
    l[3][15] = green;
    l[4][15] = green;
    l[5][15] = green;
    l[6][15] = green;
    l[7][15] = yellow;
    l[8][15] = yellow;
    l[9][15] = yellow;
    l[10][15] = yellow;
}

// game boy
void level_4(Block l[][level_size]) {
    l[2][0] = blue;
    l[3][0] = blue;
    l[4][0] = blue;
    l[5][0] = blue;
    l[6][0] = blue;
    l[7][0] = blue;
    l[8][0] = blue;
    l[9][0] = blue;
    l[10][0] = blue;
    l[11][0] = blue;

    l[1][1] = blue;
    l[2][1] = green;
    l[3][1] = green;
    l[4][1] = green;
    l[5][1] = green;
    l[6][1] = green;
    l[7][1] = green;
    l[8][1] = green;
    l[9][1] = green;
    l[10][1] = green;
    l[11][1] = green;
    l[12][1] = blue;

    l[1][2] = blue;
    l[2][2] = green;
    l[3][2] = blue;
    l[4][2] = blue;
    l[5][2] = blue;
    l[6][2] = blue;
    l[7][2] = blue;
    l[8][2] = blue;
    l[9][2] = blue;
    l[10][2] = blue;
    l[11][2] = green;
    l[12][2] = blue;

    for (int i = 3; i < 6; i++) {
    l[1][i] = blue;
    l[2][i] = green;
    l[3][i] = blue;
    l[4][i] = blue;
    l[5][i] = red;
    l[6][i] = yellow;
    l[7][i] = yellow;
    l[8][i] = yellow;
    l[9][i] = blue;
    l[10][i] = blue;
    l[11][i] = green;
    l[12][i] = blue;
    }

    l[1][6] = blue;
    l[2][6] = green;
    l[3][6] = blue;
    l[4][6] = blue;
    l[5][6] = blue;
    l[6][6] = blue;
    l[7][6] = blue;
    l[8][6] = blue;
    l[9][6] = blue;
    l[10][6] = green;
    l[11][6] = green;
    l[12][6] = blue;

    l[1][7] = blue;
    l[2][7] = green;
    l[3][7] = green;
    l[4][7] = green;
    l[5][7] = green;
    l[6][7] = green;
    l[7][7] = green;
    l[8][7] = green;
    l[9][7] = green;
    l[10][7] = green;
    l[11][7] = green;
    l[12][7] = blue;

    l[1][8] = blue;
    l[2][8] = green;
    l[3][8] = green;
    l[4][8] = green;
    l[5][8] = green;
    l[6][8] = green;
    l[7][8] = green;
    l[8][8] = green;
    l[9][8] = green;
    l[10][8] = green;
    l[11][8] = green;
    l[12][8] = blue;

    l[1][9] = blue;
    l[2][9] = green;
    l[3][9] = green;
    l[4][9] = yellow;
    l[5][9] = green;
    l[6][9] = green;
    l[7][9] = green;
    l[8][9] = green;
    l[9][9] = green;
    l[10][9] = red;
    l[11][9] = green;
    l[12][9] = blue;

    l[1][10] = blue;
    l[2][10] = green;
    l[3][10] = yellow;
    l[4][10] = yellow;
    l[5][10] = yellow;
    l[6][10] = green;
    l[7][10] = green;
    l[8][10] = green;
    l[9][10] = green;
    l[10][10] = green;
    l[11][10] = green;
    l[12][10] = blue;

    l[1][11] = blue;
    l[2][11] = green;
    l[3][11] = green;
    l[4][11] = yellow;
    l[5][11] = green;
    l[6][11] = green;
    l[7][11] = green;
    l[8][11] = red;
    l[9][11] = green;
    l[10][11] = green;
    l[11][11] = green;
    l[12][11] = blue;

    l[1][12] = blue;
    l[2][12] = green;
    l[3][12] = green;
    l[4][12] = green;
    l[5][12] = green;
    l[6][12] = green;
    l[7][12] = green;
    l[8][12] = green;
    l[9][12] = green;
    l[10][12] = green;
    l[11][12] = green;
    l[12][12] = blue;

    l[1][13] = blue;
    l[2][13] = green;
    l[3][13] = green;
    l[4][13] = green;
    l[5][13] = green;
    l[6][13] = green;
    l[7][13] = green;
    l[8][13] = green;
    l[9][13] = green;
    l[10][13] = green;
    l[11][13] = blue;
    l[12][13] = blue;

    l[2][14] = blue;
    l[3][14] = blue;
    l[4][14] = blue;
    l[5][14] = blue;
    l[6][14] = blue;
    l[7][14] = blue;
    l[8][14] = blue;
    l[9][14] = blue;
    l[10][14] = blue;
    l[11][14] = blue;
}

// link
void level_5(Block l[][level_size]){
    l[4][0] = green;
    l[5][0] = green;
    l[6][0] = green;
    l[7][0] = green;
    l[8][0] = green;
    l[9][0] = green;
    l[10][0] = green;
    l[11][0] = green;

    l[2][1] = yellow;
    l[4][1] = green;
    l[5][1] = red;
    l[6][1] = red;
    l[7][1] = red;
    l[8][1] = red;
    l[9][1] = red;
    l[10][1] = red;
    l[11][1] = green;
    l[13][1] = yellow;

    l[2][2] = yellow;
    l[4][2] = red;
    l[5][2] = red;
    l[6][2] = red;
    l[7][2] = red;
    l[8][2] = red;
    l[9][2] = red;
    l[10][2] = red;
    l[11][2] = red;
    l[13][2] = yellow;

    l[2][3] = yellow;
    l[3][3] = yellow;
    l[4][3] = red;
    l[5][3] = yellow;
    l[6][3] = green;
    l[7][3] = yellow;
    l[8][3] = yellow;
    l[9][3] = green;
    l[10][3] = yellow;
    l[11][3] = red;
    l[12][3] = yellow;
    l[13][3] = yellow;

    l[2][4] = yellow;
    l[3][4] = yellow;
    l[4][4] = red;
    l[5][4] = yellow;
    l[6][4] = red;
    l[7][4] = yellow;
    l[8][4] = yellow;
    l[9][4] = red;
    l[10][4] = yellow;
    l[11][4] = red;
    l[12][4] = yellow;
    l[13][4] = yellow;

    l[3][5] = yellow;
    l[4][5] = yellow;
    l[5][5] = yellow;
    l[6][5] = yellow;
    l[7][5] = yellow;
    l[8][5] = yellow;
    l[9][5] = yellow;
    l[10][5] = yellow;
    l[11][5] = yellow;
    l[12][5] = yellow;
    l[13][4] = red;

    l[3][6] = green;
    l[4][6] = green;
    l[5][6] = yellow;
    l[6][6] = yellow;
    l[7][6] = red;
    l[8][6] = red;
    l[9][6] = yellow;
    l[10][6] = yellow;
    l[11][6] = green;
    l[12][6] = green;
    l[13][6] = red;

    l[1][7] = blue;
    l[2][7] = blue;
    l[3][7] = blue;
    l[4][7] = blue;
    l[5][7] = blue;
    l[6][7] = yellow;
    l[7][7] = yellow;
    l[8][7] = yellow;
    l[9][7] = yellow;
    l[10][7] = green;
    l[11][7] = green;
    l[12][7] = red;
    l[13][7] = red;
    l[14][7] = red;

    l[0][8] = blue;
    l[1][8] = blue;
    l[2][8] = yellow;
    l[3][8] = blue;
    l[4][8] = blue;
    l[5][8] = blue;
    l[6][8] = blue;
    l[7][8] = green;
    l[8][8] = green;
    l[9][8] = green;
    l[10][8] = green;
    l[11][8] = green;
    l[12][8] = yellow;
    l[13][8] = red;
    l[14][8] = red;

    l[0][9] = blue;
    l[1][9] = yellow;
    l[2][9] = yellow;
    l[3][9] = yellow;
    l[4][9] = blue;
    l[5][9] = blue;
    l[6][9] = yellow;
    l[7][9] = red;
    l[8][9] = red;
    l[9][9] = green;
    l[10][9] = green;
    l[11][9] = yellow;
    l[12][9] = yellow;
    l[13][9] = yellow;
    l[14][9] = red;

    l[0][10] = blue;
    l[1][10] = blue;
    l[2][10] = yellow;
    l[3][10] = blue;
    l[4][10] = blue;
    l[5][10] = blue;
    l[6][10] = yellow;
    l[7][10] = green;
    l[8][10] = red;
    l[9][10] = red;
    l[10][10] = red;
    l[11][10] = red;
    l[12][10] = yellow;
    l[13][10] = yellow;
    l[14][10] = yellow;

    l[0][11] = blue;
    l[1][11] = blue;
    l[2][11] = yellow;
    l[3][11] = blue;
    l[4][11] = blue;
    l[5][11] = blue;
    l[6][11] = yellow;
    l[7][11] = red;
    l[8][11] = red;
    l[9][11] = green;
    l[10][11] = green;
    l[11][11] = green;
    l[12][11] = green;
    l[13][11] = yellow;

    l[0][12] = blue;
    l[1][12] = blue;
    l[2][12] = blue;
    l[3][12] = blue;
    l[4][12] = blue;
    l[5][12] = blue;
    l[6][12] = yellow;
    l[7][12] = green;
    l[8][12] = green;
    l[9][12] = green;
    l[10][12] = green;
    l[11][12] = green;

    l[1][13] = yellow;
    l[2][13] = yellow;
    l[3][13] = yellow;
    l[4][13] = yellow;
    l[5][13] = yellow;
    l[6][13] = red;
    l[9][13] = red;
    l[10][13] = red;
    l[11][13] = red;

    l[4][14] = red;
    l[5][14] = red;
    l[6][14] = red;
}

// mario
void level_6(Block l[][level_size]){
    l[4][0] = red;
    l[5][0] = red;
    l[6][0] = red;
    l[7][0] = red;
    l[8][0] = red;

    l[3][1] = red;
    l[4][1] = red;
    l[5][1] = red;
    l[6][1] = red;
    l[7][1] = red;
    l[8][1] = red;
    l[9][1] = red;
    l[10][1] = red;
    l[11][1] = red;
    l[12][1] = red;

    l[3][2] = green;
    l[4][2] = green;
    l[5][2] = green;
    l[6][2] = yellow;
    l[7][2] = yellow;
    l[8][2] = green;
    l[9][2] = yellow;

    l[2][3] = green;
    l[3][3] = yellow;
    l[4][3] = green;
    l[5][3] = yellow;
    l[6][3] = yellow;
    l[7][3] = yellow;
    l[8][3] = green;
    l[9][3] = yellow;
    l[10][3] = yellow;
    l[11][3] = yellow;

    l[2][4] = green;
    l[3][4] = yellow;
    l[4][4] = green;
    l[5][4] = green;
    l[6][4] = yellow;
    l[7][4] = yellow;
    l[8][4] = yellow;
    l[9][4] = green;
    l[10][4] = yellow;
    l[11][4] = yellow;
    l[12][4] = yellow;
    l[13][4] = yellow;

    l[2][5] = green;
    l[3][5] = green;
    l[4][5] = yellow;
    l[5][5] = yellow;
    l[6][5] = yellow;
    l[7][5] = yellow;
    l[8][5] = green;
    l[9][5] = green;
    l[10][5] = green;
    l[11][5] = green;
    l[12][5] = green;

    l[4][6] = yellow;
    l[5][6] = yellow;
    l[6][6] = yellow;
    l[7][6] = yellow;
    l[8][6] = yellow;
    l[9][6] = yellow;
    l[10][6] = yellow;
    l[11][6] = yellow;

    l[3][7] = blue;
    l[4][7] = blue;
    l[5][7] = red;
    l[6][7] = blue;
    l[7][7] = blue;
    l[8][7] = blue;

    l[2][8] = blue;
    l[3][8] = blue;
    l[4][8] = blue;
    l[5][8] = red;
    l[6][8] = blue;
    l[7][8] = blue;
    l[8][8] = red;
    l[9][8] = blue;
    l[10][8] = blue;
    l[11][8] = blue;

    l[1][9] = blue;
    l[2][9] = blue;
    l[3][9] = blue;
    l[4][9] = blue;
    l[5][9] = red;
    l[6][9] = red;
    l[7][9] = red;
    l[8][9] = red;
    l[9][9] = blue;
    l[10][9] = blue;
    l[11][9] = blue;
    l[12][9] = blue;

    l[1][10] = yellow;
    l[2][10] = yellow;
    l[3][10] = blue;
    l[4][10] = red;
    l[5][10] = yellow;
    l[6][10] = red;
    l[7][10] = red;
    l[8][10] = yellow;
    l[9][10] = red;
    l[10][10] = blue;
    l[11][10] = yellow;
    l[12][10] = yellow;

    l[1][11] = yellow;
    l[2][11] = yellow;
    l[3][11] = yellow;
    l[4][11] = red;
    l[5][11] = red;
    l[6][11] = red;
    l[7][11] = red;
    l[8][11] = red;
    l[9][11] = red;
    l[10][11] = yellow;
    l[11][11] = yellow;
    l[12][11] = yellow;

    l[1][12] = yellow;
    l[2][12] = yellow;
    l[3][12] = red;
    l[4][12] = red;
    l[5][12] = red;
    l[6][12] = red;
    l[7][12] = red;
    l[8][12] = red;
    l[9][12] = red;
    l[10][12] = red;
    l[11][12] = yellow;
    l[12][12] = yellow;

    l[3][13] = red;
    l[4][13] = red;
    l[5][13] = red;
    l[8][13] = red;
    l[9][13] = red;
    l[10][13] = red;

    l[2][14] = green;
    l[3][14] = green;
    l[4][14] = green;
    l[9][14] = green;
    l[10][14] = green;
    l[11][14] = green;

    l[1][15] = green;
    l[2][15] = green;
    l[3][15] = green;
    l[4][15] = green;
    l[9][15] = green;
    l[10][15] = green;
    l[11][15] = green;
    l[12][15] = green;
}

bool check_level(Block l[][level_size]) {
    for (int x = 0; x < level_size; x++) {
        for (int y = 0; y < level_size; y++) {
            if (l[x][y].active) {
                return false;
            }
        }
    }
    return true;
}

void clear_level(Block l[][level_size]) {
    for (int x = 0; x < level_size; x++) {
        for (int y = 0; y < level_size; y++) {
            if (l[x][y].active) {
                l[x][y].active = false;
            }
        }
    }
}

void resolve_level(Block l[][level_size]) {
    for (int x = 0; x < level_size; x++) {
        for (int y = 0; y < level_size; y++) {
            if (l[x][y].active) {
                l[x][y].posX = x*block_size;
                l[x][y].posY = y*block_size + level_offsetY;
            }
        }
    }
}