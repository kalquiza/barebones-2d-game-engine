#define SDL_MAIN_HANDLED
#include<SDL.h>
#include<GL/glew.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include"DrawUtils.h"
#include "AnimUtils.h"
#include "header.h"

// Set this to true to make the game loop exit.
char shouldExit = 0;

// The previous frame's keyboard state.
unsigned char kbPrevState[SDL_NUM_SCANCODES] = {0};

// The current frame's keyboard state.
const unsigned char* kbState = NULL;

// Position of the sprite.
int spritePos[2] = {10, 10};

// Texture for the sprite.
GLuint spriteTex;

// Size of the sprite.
int spriteSize[2];

int main(void)
{
    // Initialize SDL.
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Could not initialize SDL. ErrorCode=%s\n", SDL_GetError());
        return 1;
    }

    // Create the window and OpenGL context.
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_Window* window = SDL_CreateWindow(
            "fireguy demo",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            480, 640
            SDL_WINDOW_OPENGL);
    if (!window) {
        fprintf(stderr, "Could not create window. ErrorCode=%s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    SDL_GL_CreateContext(window);

    // Make sure we have a recent version of OpenGL.
    GLenum glewError = glewInit();
    if (glewError != GLEW_OK) {
        fprintf(stderr, "Could not initialize glew. ErrorCode=%s\n", glewGetErrorString(glewError));
        SDL_Quit();
        return 1;
    }
    if (GLEW_VERSION_2_0) {
        fprintf(stderr, "OpenGL 2.0 or greater supported: Version=%s\n",
                 glGetString(GL_VERSION));
    } else {
        fprintf(stderr, "OpenGL max supported version is too low.\n");
        SDL_Quit();
        return 1;
    }

    // Setup OpenGL state.
    glViewport(0, 0, 480, 640);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, 480, 640, 0, 0, 100);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    /*---------------------------------------------------------------------------------*/

    /* Initialize variables */
    Block level[level_size][level_size];

    int game_state = 0;
    int level_state = 0;
    int menu_selection = 0;
    bool game_complete = false;

    /* Art to draw */
    GLuint redTex[8];
    GLuint yellowTex[8];
    GLuint greenTex[8];
    GLuint blueTex[8];

    GLuint projTex[4];

    GLuint redProjTex[6];
    GLuint yellowProjTex[6];
    GLuint greenProjTex[6];
    GLuint blueProjTex[6];

    GLuint menuTex[2];
    GLuint gameoverTex[2];
    GLuint hudTex[5];
    GLuint bgTex[1];

    /* load the textures */
    redTex[0] = glTexImageTGAFile("red_00.tga", NULL, NULL);
    redTex[1] = glTexImageTGAFile("red_01.tga", NULL, NULL);
    redTex[2] = glTexImageTGAFile("red_02.tga", NULL, NULL);
    redTex[3] = glTexImageTGAFile("red_03.tga", NULL, NULL);
    redTex[4] = glTexImageTGAFile("red_04.tga", NULL, NULL);
    redTex[5] = glTexImageTGAFile("red_03.tga", NULL, NULL);
    redTex[6] = glTexImageTGAFile("red_02.tga", NULL, NULL);
    redTex[7] = glTexImageTGAFile("red_01.tga", NULL, NULL);

    yellowTex[0] = glTexImageTGAFile("yellow_00.tga", NULL, NULL);
    yellowTex[1] = glTexImageTGAFile("yellow_01.tga", NULL, NULL);
    yellowTex[2] = glTexImageTGAFile("yellow_02.tga", NULL, NULL);
    yellowTex[3] = glTexImageTGAFile("yellow_03.tga", NULL, NULL);
    yellowTex[4] = glTexImageTGAFile("yellow_04.tga", NULL, NULL);
    yellowTex[5] = glTexImageTGAFile("yellow_03.tga", NULL, NULL);
    yellowTex[6] = glTexImageTGAFile("yellow_02.tga", NULL, NULL);
    yellowTex[7] = glTexImageTGAFile("yellow_01.tga", NULL, NULL);

    greenTex[0] = glTexImageTGAFile("green_00.tga", NULL, NULL);
    greenTex[1] = glTexImageTGAFile("green_01.tga", NULL, NULL);
    greenTex[2] = glTexImageTGAFile("green_02.tga", NULL, NULL);
    greenTex[3] = glTexImageTGAFile("green_03.tga", NULL, NULL);
    greenTex[4] = glTexImageTGAFile("green_04.tga", NULL, NULL);
    greenTex[5] = glTexImageTGAFile("green_03.tga", NULL, NULL);
    greenTex[6] = glTexImageTGAFile("green_02.tga", NULL, NULL);
    greenTex[7] = glTexImageTGAFile("green_01.tga", NULL, NULL);

    blueTex[0] = glTexImageTGAFile("blue_00.tga", NULL, NULL);
    blueTex[1] = glTexImageTGAFile("blue_01.tga", NULL, NULL);
    blueTex[2] = glTexImageTGAFile("blue_02.tga", NULL, NULL);
    blueTex[3] = glTexImageTGAFile("blue_03.tga", NULL, NULL);
    blueTex[4] = glTexImageTGAFile("blue_04.tga", NULL, NULL);
    blueTex[5] = glTexImageTGAFile("blue_03.tga", NULL, NULL);
    blueTex[6] = glTexImageTGAFile("blue_02.tga", NULL, NULL);
    blueTex[7] = glTexImageTGAFile("blue_01.tga", NULL, NULL);

    projTex[0] = glTexImageTGAFile("proj_00.tga", NULL, NULL);
    projTex[1] = glTexImageTGAFile("proj_01.tga", NULL, NULL);
    projTex[2] = glTexImageTGAFile("proj_02.tga", NULL, NULL);
    projTex[3] = glTexImageTGAFile("proj_03.tga", NULL, NULL);

    menuTex[0] = glTexImageTGAFile("menu_00.tga", NULL, NULL);
    menuTex[1] = glTexImageTGAFile("menu_01.tga", NULL, NULL);
    gameoverTex[0] = glTexImageTGAFile("game_over_00.tga", NULL, NULL);
    gameoverTex[1] = glTexImageTGAFile("game_over_01.tga", NULL, NULL);
    bgTex[0] = glTexImageTGAFile("background_00.tga", NULL, NULL);

    hudTex[0] = glTexImageTGAFile("select_hud.tga", NULL, NULL);
    hudTex[1] = glTexImageTGAFile("select_arrow.tga", NULL, NULL);
    hudTex[2] = glTexImageTGAFile("lives_00.tga", NULL, NULL);

    GLuint L_RunTex[4];
    GLuint L_RunShootTex[4];
    GLuint L_JumpTex[1];
    GLuint L_FallTex[1];
    GLuint L_IdleTex[1];
    GLuint L_IdleShootTex[1];

    GLuint R_RunTex[4];
    GLuint R_RunShootTex[4];
    GLuint R_JumpTex[1];
    GLuint R_FallTex[1];
    GLuint R_IdleTex[1];
    GLuint R_IdleShootTex[1];

    L_RunTex[0] = glTexImageTGAFile("l_run_00.tga", NULL, NULL);
    L_RunTex[1] = glTexImageTGAFile("l_run_01.tga", NULL, NULL);
    L_RunTex[2] = glTexImageTGAFile("l_run_02.tga", NULL, NULL);
    L_RunTex[3] = glTexImageTGAFile("l_run_03.tga", NULL, NULL);
    L_RunShootTex[0] = glTexImageTGAFile("l_run_shoot_00.tga", NULL, NULL);
    L_RunShootTex[1] = glTexImageTGAFile("l_run_shoot_01.tga", NULL, NULL);
    L_RunShootTex[2] = glTexImageTGAFile("l_run_shoot_02.tga", NULL, NULL);
    L_RunShootTex[3] = glTexImageTGAFile("l_run_shoot_03.tga", NULL, NULL);
    L_JumpTex[0] = glTexImageTGAFile("l_jump.tga", NULL, NULL);
    L_FallTex[0] = glTexImageTGAFile("l_fall.tga", NULL, NULL);
    L_IdleTex[0] = glTexImageTGAFile("l_idle.tga", NULL, NULL);
    L_IdleShootTex[0] = glTexImageTGAFile("l_idle_shoot.tga", NULL, NULL);

    R_RunTex[0] = glTexImageTGAFile("r_run_00.tga", NULL, NULL);
    R_RunTex[1] = glTexImageTGAFile("r_run_01.tga", NULL, NULL);
    R_RunTex[2] = glTexImageTGAFile("r_run_02.tga", NULL, NULL);
    R_RunTex[3] = glTexImageTGAFile("r_run_03.tga", NULL, NULL);
    R_RunShootTex[0] = glTexImageTGAFile("r_run_shoot_00.tga", NULL, NULL);
    R_RunShootTex[1] = glTexImageTGAFile("r_run_shoot_01.tga", NULL, NULL);
    R_RunShootTex[2] = glTexImageTGAFile("r_run_shoot_02.tga", NULL, NULL);
    R_RunShootTex[3] = glTexImageTGAFile("r_run_shoot_03.tga", NULL, NULL);
    R_JumpTex[0] = glTexImageTGAFile("r_jump.tga", NULL, NULL);
    R_FallTex[0] = glTexImageTGAFile("r_fall.tga", NULL, NULL);
    R_IdleTex[0] = glTexImageTGAFile("r_idle.tga", NULL, NULL);
    R_IdleShootTex[0] = glTexImageTGAFile("r_idle_shoot.tga", NULL, NULL);

    AnimDef bgDef = { "background", {{1,1.5}}, 1 };
    AnimData bgData = { .def = &bgDef, .curFrame = 0, .timeToNextFrame = 0, .isPlaying = true};

    Player player = {
        .anim = &runData,
        .posX = 0,
        .posY = -50,
        .dir = 1,
        .sizeX = 26,
        .sizeY = 45,
        .type = 1,
        .resetPosX = true
    };

    /*---------------------------------GAME LOOP---------------------------------*/

    // The game loop.
    kbState = SDL_GetKeyboardState(NULL);
    while (!shouldExit) {
        assert(glGetError() == GL_NO_ERROR);
        memcpy(kbPrevState, kbState, sizeof(kbPrevState));

        // Handle OS message pump.
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    shouldExit = 1;
            }
        }

        // Game logic goes here.
        if (kbState[SDL_SCANCODE_ESCAPE]) {
            shouldExit = 1;
        }

        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

/*---------------------------------------------------------------------------------*/

        switch (game_state) {
            case 0:
                if (kbState[SDL_SCANCODE_DOWN]&&menu_selection==0) menu_selection = 1;
                if (kbState[SDL_SCANCODE_UP]&&menu_selection==1) menu_selection = 0;

                if (menu_selection == 0 ) glDrawSprite(menuTex[0], 0, 0, 480, 640);
                else glDrawSprite(menuTex[1], 0, 0, 480, 640);

                if ((kbState[SDL_SCANCODE_Z]&&!kbPrevState[SDL_SCANCODE_Z])||
                    (kbState[SDL_SCANCODE_X]&&!kbPrevState[SDL_SCANCODE_X])||
                    (kbState[SDL_SCANCODE_C]&&!kbPrevState[SDL_SCANCODE_C])) {
                    if (menu_selection == 0) {
                        for (int x = 0; x < level_size; x++) {
                            for (int y = 0; y < level_size; y++) {
                                level[x][y].active = false;
                            }
                        }
                        level_1(level);
                        resolve_level(level);
                        game_state = 1;
                        level_state = 1;
                        player.lives = 4;
                        player.score = 0;
                        player.type = 1;
                        game_complete = false;
                    }
                    if (menu_selection == 1){
                        SDL_Quit();
                        return 0;
                    }
                }
                break;
            case 1: // level

        /*---------------------------------DRAW LEVEL---------------------------------*/

        glDrawSprite(bgTex[0], 0, 0, 480, 640);

        // HUD
        glDrawSprite(hudTex[0], 16, 16, 88, 16);
        switch(player.type) {
            case 1:
                glDrawSprite(hudTex[1], 16, 38, 16, 16);
                break;
            case 2:
                glDrawSprite(hudTex[1], 40, 38, 16, 16);
                break;
            case 3:
                glDrawSprite(hudTex[1], 64, 38, 16, 16);
                break;
            case 4:
                glDrawSprite(hudTex[1], 88, 38, 16, 16);
                break;
        }
        int space = 0;
        for (int i = 0; i < player.lives-1; i++) {
            glDrawSprite(hudTex[2], 432 - space, 6, 32, 32);
            space += 32;
        }

        for (int y = 0; y < level_size; y++) {
            for (int x = 0; x < level_size; x++) {
                if (level[x][y].active) {
                if (!level[x][y].anim->isPlaying) animSet(level[x][y].anim, level[x][y].anim->def);
                    if (player.resetPosX) {
                        player.posX = level[x][y].posX-12;
                        player.resetPosX = false;
                    }

                    animTick(level[x][y].anim, 0.0002);
                    switch (level[x][y].type){
                    case 1:
                        animDraw( level[x][y].anim, redTex, x*block_size, y*block_size + level_offsetY, level[x][y].sizeX, level[x][y].sizeY);
                        break;
                    case 2:
                        animDraw( level[x][y].anim, yellowTex, x*block_size, y*block_size + level_offsetY, level[x][y].sizeX, level[x][y].sizeY);
                        break;
                    case 3:
                        animDraw( level[x][y].anim,greenTex, x*block_size, y*block_size + level_offsetY, level[x][y].sizeX, level[x][y].sizeY);
                        break;
                    case 4:
                        animDraw( level[x][y].anim, blueTex, x*block_size, y*block_size + level_offsetY, level[x][y].sizeX, level[x][y].sizeY);
                        break;
                    }
                }
            }
        }

    /*---------------------------------PLAYER MOVEMENT---------------------------------*/

        // Horizontal Movement
        if (kbPrevState[SDL_SCANCODE_LEFT]&!kbPrevState[SDL_SCANCODE_RIGHT]) {
            player.hspd= -player_hspd;
            player.dir = -1;
        }
        if (kbPrevState[SDL_SCANCODE_RIGHT]&!kbPrevState[SDL_SCANCODE_LEFT]){
            player.hspd= player_hspd;
            player.dir = 1;
        }

        // Projectile Selection
        if (kbState[SDL_SCANCODE_Z] && !kbPrevState[SDL_SCANCODE_Z]) {
            player.type++;
            if (player.type > 4) player.type = 1;
        }

        // In air
        if (!collide_player_to_level(player, level, 0, 1)) {
            player.vspd += player_grav;
            if (kbState[SDL_SCANCODE_X] && !kbPrevState[SDL_SCANCODE_X]) {
                for (int i = 0; i < projectile_count; i++) {
                    if (!player.projectiles[i].active) {
                        player.projectiles[i] = proj;
                        player.projectiles[i].type = player.type;
                        player.projectiles[i].active = true;
                        player.projectiles[i].hspd = player.dir * projectile_hspd;
                        player.projectiles[i].vspd = projectile_vspd;
                        player.projectiles[i].posY = player.posY+20;
                        if (player.dir > 0) player.projectiles[i].posX = player.posX+45;
                        else player.projectiles[i].posX = player.posX+5;
                        if (kbState[SDL_SCANCODE_UP]) {
                            player.projectiles[i].hspd = player.dir * projectile_up_hspd;
                            player.projectiles[i].vspd = projectile_up_vspd;
                        }
                        if (kbState[SDL_SCANCODE_DOWN]) {
                            player.projectiles[i].hspd = player.dir * projectile_down_hspd;
                            player.projectiles[i].vspd = 0;
                        }
                        break;
                    }
                }
            }
        }
        // On block
        if (collide_player_to_level(player, level, 0, 1)) {
            player.vspd = 0;
            if (kbState[SDL_SCANCODE_C] && !kbPrevState[SDL_SCANCODE_C]) player.vspd= player_jump;
            // Keyboard check – idle shoot
            if (kbState[SDL_SCANCODE_X] && !kbPrevState[SDL_SCANCODE_X]) {
                for (int i = 0; i < projectile_count; i++) {
                    if (!player.projectiles[i].active) {
                        player.projectiles[i] = proj;
                        player.projectiles[i].type = player.type;
                        player.projectiles[i].active = true;
                        player.projectiles[i].hspd = player.dir * projectile_hspd;
                        player.projectiles[i].vspd = projectile_vspd;
                        player.projectiles[i].posY = player.posY+20;
                        if (player.dir > 0) player.projectiles[i].posX = player.posX+45;
                        else player.projectiles[i].posX = player.posX+5;
                        if (kbState[SDL_SCANCODE_UP]) {
                            player.projectiles[i].hspd = player.dir * projectile_up_hspd;
                            player.projectiles[i].vspd = projectile_up_vspd;
                        }
                        if (kbState[SDL_SCANCODE_DOWN]) {
                            player.projectiles[i].hspd = player.dir * projectile_down_hspd;
                            player.projectiles[i].vspd = 0;
                        }
                        break;
                    }
                }
            }

        }


        // Horizontal Movement
        for (int i = abs(player.hspd); i > 0; i--) {
            if (collide_player_to_level(player, level, copysign(1, player.hspd), 0)||
                player.posX+12+copysign(1, player.hspd)<0||
                player.posX+38+copysign(1, player.hspd)>480) {
                player.hspd = 0;
                break;
            }
            player.posX += copysign(1, player.hspd);
            player.hspd += -(copysign(1, player.hspd));
        }

        // Vertical Movement
        for (int i = abs(player.vspd); i > 0; i--) {
            if (!collide_player_to_level(player, level, 0, copysign(1, player.vspd)))player.posY += copysign(1, player.vspd);
            if (collide_player_to_level(player, level, 0, 1)||collide_player_to_level(player, level, 0, -1)||player.posY+50>640) {
                player.vspd = 0;
                break;
            }
            if (kbPrevState[SDL_SCANCODE_C] && !kbState[SDL_SCANCODE_C]&& player.vspd < 0) {
                player.vspd= 0;
                break;
            }
        }

        // Draw Player
        //if (!level[x][y].anim->isPlaying) animSet(level[x][y].anim, level[x][y].anim->def);
        animTick(player.anim, 0.1);

        // In air
        if (!collide_player_to_level(player, level, 0, 1)) {
            if (player.dir > 0) {
                if (kbState[SDL_SCANCODE_X]) glDrawSprite(R_JumpTex[0], player.posX, player.posY, 50, 50);
                else glDrawSprite(R_FallTex[0], player.posX, player.posY, 50, 50);
            }
            else {
                if (kbState[SDL_SCANCODE_X]) glDrawSprite(L_JumpTex[0], player.posX, player.posY, 50, 50);
                else glDrawSprite(L_FallTex[0], player.posX, player.posY, 50, 50);
            }
        }

        // On block
        if (collide_player_to_level(player, level, 0, 1)) {
            if (kbState[SDL_SCANCODE_LEFT]&!kbPrevState[SDL_SCANCODE_RIGHT]) {
                if (!player.anim->isPlaying) animSet(player.anim, player.anim->def);
                else animTick(player.anim, 0.001);
                if (kbState[SDL_SCANCODE_X]) animDraw(player.anim, L_RunShootTex, player.posX, player.posY, 50,50); // run shoot
                else animDraw(player.anim, L_RunTex, player.posX, player.posY, 50,50);
            }
            else if (kbState[SDL_SCANCODE_RIGHT]&!kbPrevState[SDL_SCANCODE_LEFT]) {
                if (!player.anim->isPlaying) animSet(player.anim, player.anim->def);
                else animTick(player.anim, 0.001);
                if (kbState[SDL_SCANCODE_X]) animDraw(player.anim, R_RunShootTex, player.posX, player.posY, 50,50); // run shoot
                else animDraw(player.anim, R_RunTex, player.posX, player.posY, 50,50);
            }
            else if (kbState[SDL_SCANCODE_X]) {
                    if (player.dir > 0) glDrawSprite(R_IdleShootTex[0], player.posX, player.posY, 50, 50);
                    else glDrawSprite(L_IdleShootTex[0], player.posX, player.posY, 50, 50);
            }
            else {
                if (player.dir > 0) glDrawSprite(R_IdleTex[0], player.posX, player.posY, 50, 50);
                else glDrawSprite(L_IdleTex[0], player.posX, player.posY, 50, 50);
            }
        }


        if (player.posY+player.sizeY + 50 > 640) {
            if (check_level(level)) {
                level_state++;
                player.posY = -50;
                player.vspd = 0;
                switch(level_state) {
                    case 1:
                        clear_level(level);
                        level_1(level);
                        resolve_level(level);
                        break;
                    case 2:
                        clear_level(level);
                        level_2(level);
                        resolve_level(level);
                        break;
                    case 3:
                        clear_level(level);
                        level_3(level);
                        resolve_level(level);
                        break;
                    case 4:
                        clear_level(level);
                        level_4(level);
                        resolve_level(level);
                        break;
                    case 5:
                        clear_level(level);
                        level_5(level);
                        resolve_level(level);
                        break;
                    case 6:
                        clear_level(level);
                        level_6(level);
                        resolve_level(level);
                        break;
                    default:
                        level_state = 0;
                        game_state = 2;
                        game_complete = true;
                        break;
                }
            } else {
                player.lives--;
                player.posY = -50;
                player.vspd = 0;
                if (player.lives < 1) {
                    level_state = 0;
                    game_state = 2;
                }
            }
            player.resetPosX = true;
        }

        /*---------------------------------PROJECTILE MOVEMENT---------------------------------*/

        for(int i = 0; i < projectile_count; i++) {
            if (player.projectiles[i].active) {
                player.projectiles[i].vspd += projectile_grav;
                for (int x = 0; x < level_size; x++) {
                    for (int y = 0; y < level_size; y++) {
                        if (level[x][y].active) {
                            if (collide_projectile_to_block(player.projectiles[i], level[x][y], 0, 1)) {
                                player.projectiles[i].vspd = 0;
                            }
                        }
                    }
                }

                // Horizontal Movement
                for (int j = abs(player.projectiles[i].hspd); j > 0; j--) {
                    for (int x = 0; x < level_size; x++) {
                        for (int y = 0; y < level_size; y++) {
                            if (level[x][y].active&&player.projectiles[i].active) {
                                if (collide_projectile_to_block(player.projectiles[i], level[x][y], copysign(1, player.hspd), 0)) {
                                    if (player.projectiles[i].type == level[x][y].type||level[x][y].type==5) {
                                        player.projectiles[i].active = false;
                                        player.projectiles[i].vspd = 0;
                                        player.projectiles[i].hspd = 0;

                                        level[x][y].active = false;
                                    }
                                    else {
                                        player.projectiles[i].hspd = copysign(projectile_hspd, player.projectiles[i].hspd);
                                        player.projectiles[i].hspd = -player.projectiles[i].hspd;
                                        player.projectiles[i].bounce_count++;
                                    }
                                }
                            }
                        }
                    }
                    if (player.projectiles[i].posX == 0 || player.projectiles[i].posX == (480-player.projectiles[i].sizeX)) {
                        player.projectiles[i].hspd = -player.projectiles[i].hspd;
                        player.projectiles[i].bounce_count++;

                    }
                    player.projectiles[i].posX += copysign(1, player.projectiles[i].hspd);
                }

                // Vertical Movement
                for (int j = abs(player.projectiles[i].vspd); j > 0; j--) {
                    player.projectiles[i].posY += copysign(1, player.projectiles[i].vspd);
                    for (int x = 0; x < level_size; x++) {
                        for (int y = 0; y < level_size; y++) {
                            if (level[x][y].active && player.projectiles[i].active) {
                                if (collide_projectile_to_block(player.projectiles[i], level[x][y], 0, 1)) {
                                    if (player.projectiles[i].type == level[x][y].type) {
                                        player.projectiles[i].active = false;
                                        level[x][y].active = false;
                                        break;
                                    }
                                    else {
                                        player.projectiles[i].vspd = projectile_bounce;
                                        player.projectiles[i].hspd = copysign(projectile_hspd, player.projectiles[i].hspd);
                                        player.projectiles[i].bounce_count++;
                                    }
                                }
                                if (collide_projectile_to_block(player.projectiles[i], level[x][y], 0, -1)) {
                                    if (player.projectiles[i].type == level[x][y].type||level[x][y].type==5) {
                                        player.projectiles[i].active = false;
                                        level[x][y].active = false;
                                        break;
                                    }
                                    else {
                                        player.projectiles[i].vspd = -projectile_bounce;
                                        player.projectiles[i].hspd = copysign(projectile_hspd, player.projectiles[i].hspd);
                                        player.projectiles[i].bounce_count++;
                                    }
                                }

                            }
                        }
                    }
                }
            }

            if (player.projectiles[i].bounce_count > projectile_bounce_limit || player.projectiles[i].posY > 640) player.projectiles[i].active = false;


            if (player.projectiles[i].active){
                switch (player.projectiles[i].type) {
                    case 1:
                        glDrawSprite(projTex[0], player.projectiles[i].posX, player.projectiles[i].posY, player.projectiles[i].sizeX, player.projectiles[i].sizeY);
                        break;
                    case 2:
                        glDrawSprite(projTex[1], player.projectiles[i].posX, player.projectiles[i].posY, player.projectiles[i].sizeX, player.projectiles[i].sizeY);
                        break;
                    case 3:
                        glDrawSprite(projTex[2], player.projectiles[i].posX, player.projectiles[i].posY, player.projectiles[i].sizeX, player.projectiles[i].sizeY);
                        break;
                    case 4:
                        glDrawSprite(projTex[3], player.projectiles[i].posX, player.projectiles[i].posY, player.projectiles[i].sizeX, player.projectiles[i].sizeY);
                        break;
                }
            }
        }

        /*---------------------------------END PROJECTILE LOOP---------------------------------*/

            break;
            case 2: // game_over
                if (game_complete) glDrawSprite(gameoverTex[1], 0, 0, 480, 640);
                else glDrawSprite(gameoverTex[0], 0, 0, 480, 640);

                if (kbState[SDL_SCANCODE_Z]||kbState[SDL_SCANCODE_X]||kbState[SDL_SCANCODE_C]) {
                    game_state = 0;
                }
                break;
        }

        // Present the most recent frame.
        SDL_GL_SwapWindow(window);
    }

    SDL_Quit();

    return 0;
}