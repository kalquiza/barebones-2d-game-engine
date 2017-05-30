/**
    AnimUtils.c

    @author Kristoffer Alquiza
*/

#include <OpenGL/gl3.h>
#include <stdbool.h>
#include "DrawUtils.h"
#include "AnimUtils.h"

void animTick( AnimData* data, float dt ) {
    if( !data->isPlaying ) {
        return;
    }

    int numFrames = data->def->numFrames;
    data->timeToNextFrame -= dt;
    if (data->timeToNextFrame < 0 ) {
        ++data->curFrame;
        if( data->curFrame >= numFrames ) {
            // end of the animation, stop it
            data->curFrame = numFrames - 1;
            data->timeToNextFrame = 0;
            data->isPlaying = false;
        } else {
            AnimFrameDef* curFrame = &data->def->frames[data->curFrame];
            data->timeToNextFrame += curFrame->frameTime;
        }
    }
}

void animSet( AnimData* anim, AnimDef* toPlay ) {
    anim->def = toPlay;
    anim->curFrame = 0;
    anim->timeToNextFrame = anim->def->frames[0].frameTime;
    anim->isPlaying = true;
}

void animReset( AnimData* anim ) {
    animSet( anim, anim->def );
}

void animDraw( AnimData* anim, GLuint textures[], int x, int y, int w, int h ) {
    int curFrameNum = anim->def->frames[anim->curFrame].frameNum;
    GLuint tex = textures[curFrameNum-1];
    glDrawSprite( tex, x, y, w, h );
}
