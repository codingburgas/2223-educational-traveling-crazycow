#include "Main.h"

void Menu(bool* isGameClosed, bool* isMenuOpen, bool* openMap, int* BusX, int* BusY,
    int* BGX, int* countryNumber, AllTextures textures, Font font)
{
    if (*isMenuOpen)
    {
        UpdateMusicStream(textures.menuMusic);

        DrawMenuBackground(BusX, BusY, BGX, textures);
        StartGame(isMenuOpen, openMap, countryNumber, textures, font);
        CloseGame(isGameClosed, textures, font);
    }
}

void DrawMenuBackground(int* BusX, int* BusY, int* BGX, AllTextures textures)
{   
    int currentFPS = GetFPS();
    static int counter = 0;
    static float frameTime = 0; 
    static bool framePosition = false;
    int updateVertical;
    int updateFrameTime = frameTime * 200;

    DrawTexture(textures.background, *BGX, 0, WHITE);
    DrawTexture(textures.background, *BGX + 1920, 0, WHITE);

    if (currentFPS > 60)
    {
        updateVertical = frameTime + 90;
    }
    else if (currentFPS <= 30)
    {
        updateVertical = frameTime + 20;
    }
    else
    {
        updateVertical = frameTime + 40;
    }

    counter++;
    if (counter >= updateVertical)
    {
        *BusY += 3;
        counter = 0;
    }
    
    if (*BusY == 596)
    {
        *BusY = 590;
        framePosition =!framePosition;
    }

    if (*BusY > 590)
    {
        DrawTexture(textures.menuCaravanMiddle, *BusX, *BusY, WHITE);
    }
    else
    {
        if (!framePosition)
        {
            DrawTexture(textures.menuCaravanLeft, *BusX, *BusY, WHITE);
        }
        else
        {
            DrawTexture(textures.menuCaravanRight, *BusX, *BusY, WHITE);
        }
    }

    *BGX -= updateFrameTime;
    if (*BGX <= -1920)
    {
        *BGX = 0;
    }

    *BusX += updateFrameTime;
    if (*BusX >= 1920)
    {
        *BusX = -650;
    }

    frameTime = GetFrameTime();
}

void StartGame(bool* isMenuOpen, bool* openMap, int* countryNumber, AllTextures textures, Font font)
{
    DrawTexture(textures.startBlock, 676, 280, WHITE);
    Vector2 pos = {814,316};
    DrawTextEx(font, "Start", pos, 96, 4, BLACK);
    if (IsMouseInRange(676, 676 + 480, 280, 280 + 149))
    {
        pos.x = 816;
        pos.y = 310;
        DrawTextEx(font, "Start", pos, 96, 4, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            PlaySoundMulti(textures.clickSound);
            *countryNumber = 0;
            *isMenuOpen = false;
            *openMap = true;
        }
    }
}

void CloseGame(bool* isGameClosed, AllTextures textures, Font font)
{
    DrawTexture(textures.startBlock, 676, 500, WHITE);
    Vector2 pos = {844,536};
    DrawTextEx(font, "Exit", pos, 96, 4, BLACK);
    if (IsMouseInRange(676, 676 + 480, 500, 500 + 149))
    {
        pos.x = 846;
        pos.y = 530;
        DrawTextEx(font, "Exit", pos, 96, 4, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            PlaySoundMulti(textures.clickSound);
            *isGameClosed = true;
        }
    }
}