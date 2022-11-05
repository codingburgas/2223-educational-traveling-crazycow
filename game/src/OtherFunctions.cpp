#include "Functions.h"

bool IsMouseInRange(int x1, int x2, int y1, int y2)
{
    if (GetMouseX() >= x1 && GetMouseX() <= x2 && GetMouseY() >= y1 && GetMouseY() <= y2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
int frameDelay = 8;
int currentFrame = 0;
int frameCounter = 0;
unsigned int nextFrame = 0;

void DrawAnimation(Animation animation, int x, int y, Color color)
{

    frameCounter++;
    if (frameCounter >= frameDelay)
    {
        currentFrame++;
        if (currentFrame >= animation.frames)
        {
            currentFrame = 0;
        }
        nextFrame = animation.image.width * animation.image.height * 4 * currentFrame;
        UpdateTexture(animation.texture, ((unsigned char*)animation.image.data) + nextFrame);

        frameCounter = 0;
    }
    DrawTexture(animation.texture, x, y, color);
}
*/

void unloadAllTextures(AllTextures unloadTextures)
{
    UnloadTexture(unloadTextures.busIcon);
    UnloadTexture(unloadTextures.closeSettingsIcon);
    UnloadTexture(unloadTextures.europeMap);
    UnloadTexture(unloadTextures.settingsBox);
    UnloadTexture(unloadTextures.settingsIcon);
    UnloadTexture(unloadTextures.startBlock);
    UnloadTexture(unloadTextures.taskBox);
}

/*void unloadAllAnimations(Animation animation)
{
    UnloadImage(animation.image);
    UnloadTexture(animation.texture);
}*/