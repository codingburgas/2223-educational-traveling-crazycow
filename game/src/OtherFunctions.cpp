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

Vector2 VecPos(int x, int y)
{
    Vector2 pos;
    pos.x = x;
    pos.y = y;
    return pos;
}

void UnloadAllTextures(AllTextures unloadTextures)
{
    UnloadTexture(unloadTextures.busIcon);
    UnloadTexture(unloadTextures.closeSettingsIcon);
    UnloadTexture(unloadTextures.settingsBox);
    UnloadTexture(unloadTextures.settingsIcon);
    UnloadTexture(unloadTextures.startBlock);
    UnloadTexture(unloadTextures.taskBox);
    UnloadTexture(unloadTextures.background);
    UnloadTexture(unloadTextures.leftArrow);
    UnloadTexture(unloadTextures.rightArrow);
    UnloadTexture(unloadTextures.woodBox);
    UnloadTexture(unloadTextures.quizBox);
    UnloadTexture(unloadTextures.answerBlock);
    UnloadTexture(unloadTextures.wheatIcon);

    UnloadTexture(unloadTextures.europeMap);
    UnloadTexture(unloadTextures.europeBulgaria);
    UnloadTexture(unloadTextures.europeSpain);
    UnloadTexture(unloadTextures.europeFrance);
    UnloadTexture(unloadTextures.europeItaly);
    UnloadTexture(unloadTextures.europeGermany);
    UnloadTexture(unloadTextures.europeTurkey);
    UnloadTexture(unloadTextures.europeGreece);
    UnloadTexture(unloadTextures.europeEngland);
    UnloadTexture(unloadTextures.europeNorway);
}