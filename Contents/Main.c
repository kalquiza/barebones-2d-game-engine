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

        // Game drawing goes here.
        glDrawSprite(spriteTex, spritePos[0], spritePos[1], spriteSize[0], spriteSize[1]);

        // Present the most recent frame.
        SDL_GL_SwapWindow(window);
    }

    SDL_Quit();

    return 0;
}