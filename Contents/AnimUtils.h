/**
    AnimUtils.h

    @author Kristoffer Alquiza
*/

#ifndef CS134_Final_Project_animation_h
#define CS134_Final_Project_animation_h

#include <OpenGL/gl3.h>
#include <stdbool.h>

typedef struct AnimFrameDef {
    // combined with the AnimDef's name to make
    // the actual texture name
    int frameNum;
    float frameTime;
} AnimFrameDef;

typedef struct AnimDef {
    const char* name;
    AnimFrameDef frames[20];
    int numFrames;
} AnimDef;

// Runtime state for an animation
typedef struct AnimData {
    AnimDef* def;
    int curFrame;
    float timeToNextFrame;
    bool isPlaying;
} AnimData;

void animTick( AnimData* data, float dt );
void animSet( AnimData* anim, AnimDef* toPlay );
void animReset( AnimData* anim );
void animDraw( AnimData* anim, GLuint textures[], int x, int y, int w, int h );

#endif
