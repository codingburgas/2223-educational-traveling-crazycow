#include "Functions.h"

void Menu(bool* Close, bool* areSettingsOpen, bool* isMenuOpen, int* countryNumber, bool* chooseCountry, int* BusX, int* BusY,
    int* BGX, AllTextures textures, Animation animation)
{
    DrawMenuBackground(BusX, BusY, BGX, textures, animation);
    if (*isMenuOpen)
    {
        StartGame(isMenuOpen, chooseCountry, textures);
        CloseGame(Close, textures);
    }

    if (*chooseCountry)
    {
        ChooseStartCountry(countryNumber, textures);
    }

    DrawTexture(textures.settingsIcon, 5, 5, GRAY);
    OpenSettings(areSettingsOpen, isMenuOpen, chooseCountry, textures);
    CloseSetting(areSettingsOpen, textures);
}

int counter = 0;
void DrawMenuBackground(int* BusX, int* BusY, int* BGX, AllTextures textures, Animation animation)
{
    //DrawAnimation(animation, 0, 0, WHITE);
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
    DrawTexture(textures.startBlock, 660, 400, WHITE);
    DrawText("START", 730, 410, 110, LIME);
    if (IsMouseInRange(660, 660 + 511, 400, 400 + 116))
    {
        DrawText("START", 730, 403, 110, GREEN);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true)
        {
            *isMenuOpen = false;
            *chooseCountry = true;
        }
    }
}

void CloseGame(bool* isGameClosed, AllTextures textures)
{
    DrawTexture(textures.startBlock, 660, 600, WHITE);
    DrawText("EXIT", 780, 610, 110, LIME);
    if (IsMouseInRange(660, 660 + 511, 600, 600 + 116))
    {
        DrawText("EXIT", 780, 603, 110, GREEN);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true)
        {
            *isGameClosed = true;
        }
    }
}