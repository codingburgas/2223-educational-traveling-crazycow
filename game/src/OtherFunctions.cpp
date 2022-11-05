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