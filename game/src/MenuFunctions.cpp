#include "Functions.h"

void Menu(bool* isGameClosed, bool* isMenuOpen, bool* chooseCountry, int* BusX, int* BusY,
    int* BGX, AllTextures textures)
{
    if (*isMenuOpen)
    {
        DrawMenuBackground(BusX, BusY, BGX, textures);
        StartGame(isMenuOpen, chooseCountry, textures);
        CloseGame(isGameClosed, textures);
    }
}

int counter = 0;
void DrawMenuBackground(int* BusX, int* BusY, int* BGX, AllTextures textures)
{
    DrawTexture(textures.background, *BGX, 0, WHITE);
    DrawTexture(textures.background, *BGX + 1919, 0, WHITE);
    DrawTexture(textures.busIcon, *BusX, *BusY, WHITE);

    *BGX -= 5;
    if (*BGX <= -1920)
    {
        *BGX = 0;
    }

    *BusX += 5;
    if (*BusX >= 1920)
    {
        *BusX = -600;
    }

    counter++;
    if (counter == 12)
    {
        *BusY += 3;
        counter = 0;
    }
    if (*BusY == 606)
    {
        *BusY = 600;
    }
}

void StartGame(bool* isMenuOpen, bool* chooseCountry, AllTextures textures)
{
    DrawTexture(textures.startBlock, 676, 280, WHITE);
    DrawText("START", 676 + 80, 316, 96, BLACK);
    if (IsMouseInRange(676, 676 + 480, 280, 280 + 149))
    {
        DrawText("START", 676 + 80, 310, 96, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true)
        {
            *isMenuOpen = false;
            *chooseCountry = true;
        }
    }
}

void CloseGame(bool* isGameClosed, AllTextures textures)
{
    DrawTexture(textures.startBlock, 676, 500, WHITE);
    DrawText("EXIT", 676 + 130, 536, 96, BLACK);
    if (IsMouseInRange(676, 676 + 480, 500, 500 + 149))
    {
        DrawText("EXIT", 676 + 130, 530, 96, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true)
        {
            *isGameClosed = true;
        }
    }
}