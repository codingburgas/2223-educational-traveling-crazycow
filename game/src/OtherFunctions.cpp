#include "Main.h"

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
    Vector2 pos = {0,0};
    pos.x = x;
    pos.y = y;
    return pos;
}

void UnloadAllTextures(AllTextures unloadTextures)
{
    // Unload Boxes

    UnloadTexture(unloadTextures.settingsBox);
    UnloadTexture(unloadTextures.woodBox);
    UnloadTexture(unloadTextures.quizBox);
    UnloadTexture(unloadTextures.taskBox);
    
    UnloadTexture(unloadTextures.startBlock);
    UnloadTexture(unloadTextures.answerBlock);
    
    UnloadTexture(unloadTextures.leftArrow);
    UnloadTexture(unloadTextures.rightArrow);
    
    // Unload Maps

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

    // Unload Backgrounds

    UnloadTexture(unloadTextures.background);

    UnloadTexture(unloadTextures.quizBackgroundBulgaria);
    UnloadTexture(unloadTextures.quizBackgroundFrance);
    UnloadTexture(unloadTextures.quizBackgroundItaly);
    UnloadTexture(unloadTextures.quizBackgroundSpain);

    UnloadTexture(unloadTextures.menuCaravanLeft);
    UnloadTexture(unloadTextures.menuCaravanMiddle);
    UnloadTexture(unloadTextures.menuCaravanRight);

    // Unload Others

    UnloadTexture(unloadTextures.settingsIcon);
    UnloadTexture(unloadTextures.closeSettingsIcon);
    UnloadTexture(unloadTextures.wheatIcon);
    UnloadTexture(unloadTextures.chain);
}