/**
    Header.h

    @author Kristoffer Alquiza
*/

#ifndef collision_h
#define collision_h

#include<SDL.h>
#include "AnimUtils.h"

static const int level_size = 20;
static const int level_offsetY = 96;
static const int block_size = 32;
static const int player_jump = -15;
static const int player_hspd = 4;
static const int player_grav = 1;

static const int projectile_size = 8;
static const int projectile_count = 5;

static const int projectile_hspd = 10;
static const int projectile_vspd = 0;

static const int projectile_up_hspd = 10;
static const int projectile_up_vspd = -10;

static const int projectile_down_hspd = 1;

static const int projectile_grav = 1;

static const int projectile_bounce = -10;
static const int projectile_bounce_limit = 10;


typedef struct Projectile
{
    AnimData *anim;
    int posX;
    int posY;
    int sizeX;
    int sizeY;
    double vspd;
    int hspd;
    int type;
    int bounce_count;
    bool active;
} Projectile;

typedef struct Block
{
    AnimData *anim;
    int posX;
    int posY;
    int sizeX;
    int sizeY;
    int type;
    bool active;
} Block;

typedef struct Player
{
    AnimData *anim;
    int posX;
    int posY;
    int dir;
    int sizeX;
    int sizeY;
    int vspd;
    int hspd;
    int lives;
    int score;
    int type;
    bool resetPosX;
    Projectile projectiles[projectile_count];
} Player;

// Blocks
static const AnimDef redDef = { "red", {{1,.1},{2,.1},{3,.1},{4,.1},{5,.1},{6,.1},{7,.1},{8,.1}}, 8 };
static const AnimData redData = { .def = &redDef, .curFrame = 0, .timeToNextFrame = 0, .isPlaying = false};
static const Block red = {
    .anim = & redData,
    .sizeX = block_size,
    .sizeY = block_size,
    .type = 1,
    .active = true
};

static const AnimDef yellowDef = { "yellow", {{1,.1},{2,.1},{3,.1},{4,.1},{5,.1},{6,.1},{7,.1},{8,.1}}, 8 };
static const AnimData yellowData = { .def = &yellowDef, .curFrame = 0, .timeToNextFrame = 0, .isPlaying = false};
static const Block yellow = {
    .anim = & yellowData,
    .sizeX = block_size,
    .sizeY = block_size,
    .type = 2,
    .active = true
};

static const AnimDef greenDef = { "green", {{1,.1},{2,.1},{3,.1},{4,.1},{5,.1},{6,.1},{7,.1},{8,.1}}, 8 };
static const AnimData greenData = { .def = &greenDef, .curFrame = 0, .timeToNextFrame = 0, .isPlaying = false};
static const Block green = {
    .anim = & greenData,
    .sizeX = block_size,
    .sizeY = block_size,
    .type = 3,
    .active = true
};

static const AnimDef blueDef = { "blue", {{1,.1},{2,.1},{3,.1},{4,.1},{5,.1},{6,.1},{7,.1},{8,.1}}, 8 };
static const AnimData blueData = { .def = &blueDef, .curFrame = 0, .timeToNextFrame = 0, .isPlaying = false};
static const Block blue = {
    .anim = &blueData,
    .sizeX = block_size,
    .sizeY = block_size,
    .type = 4,
    .active = true
};

static const AnimDef greyDef = { "grey", {{1,.1},{2,.1},{3,.1},{4,.1},{5,.1},{6,.1},{7,.1},{8,.1}}, 8 };
static const AnimData greyData = { .def = &greyDef, .curFrame = 0, .timeToNextFrame = 0, .isPlaying = false};
static const Block grey = {
    .anim = &greyData,
    .sizeX = block_size,
    .sizeY = block_size,
    .type = 5,
    .active = true
};

// Projectile
static const AnimDef projDef = { "projectile", {{1,.1}}, 1  };
static const AnimData projData = { .def = &projDef, .curFrame = 0, .timeToNextFrame = 0, .isPlaying = false};
static const Projectile proj = {
    .anim = &projData,
    .sizeX = projectile_size,
    .sizeY = projectile_size,
    .vspd = 0,
    .hspd = 0,
    .bounce_count = 0,
    .active = false
};

// Player Animation Definitions

static const AnimDef runDef = { "run", {{1,1},{2,1},{3,1},{4,1}}, 4  };
static const AnimData runData = { .def = &runDef, .curFrame = 0, .timeToNextFrame = 0, .isPlaying = false};

void reset_player(Player p);
void move_player_move(Player p);
void move_projectile(Projectile p);

bool collide_player_to_block(Player p, Block b, int x, int y);
bool collide_player_to_level(Player p, Block l[][level_size], int x, int y);
bool collide_projectile_to_block(Projectile p, Block b, int x, int y);


void level_0(Block l[][level_size]);
void level_1(Block l[][level_size]);
void level_2(Block l[][level_size]);
void level_3(Block l[][level_size]);
void level_4(Block l[][level_size]);
void level_5(Block l[][level_size]);
void level_6(Block l[][level_size]);
void level_7(Block l[][level_size]);
void level_8(Block l[][level_size]);


bool check_level(Block level[][level_size]);
void resolve_level(Block l[][level_size]);
void clear_level(Block l[][level_size]);

#endif
