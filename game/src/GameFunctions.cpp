#include "Functions.h"

void Game(bool* chooseCountry, int* countryNumber, bool* countryList, AllTextures textures)
{
    if (*chooseCountry)
    {
        ChooseCountry(countryNumber, countryList, textures);
    }
}

int mapLock = 0;
void ChooseCountry(int* countryNumber, bool* countryList, AllTextures textures)
{
    DrawTexture(textures.europeMap, mapLock, 0, WHITE);

    DrawRectangle(0, 60, 35, 35, WHITE);

    if (IsMouseInRange(0, 35, 60, 60 + 35))
    {
        DrawRectangle(0, 60, 35, 35, GRAY);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            *countryList = true;
        }
    }

    if (*countryList)
    {
        DrawRectangle(1920 - 35, 0, 35, 35, WHITE);
        if (IsMouseInRange(1920 - 35, 1920, 0, 35))
        {
            DrawRectangle(1920 - 35, 0, 35, 35, GRAY);
            if (mapLock >= 10 && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                mapLock -= 10;
            }
        }

        DrawRectangle(1920 - 70, 0, 35, 35, WHITE);
        if (IsMouseInRange(1920 - 70, 1920 - 35, 0, 35))
        {
            DrawRectangle(1920 - 70, 0, 35, 35, GRAY);
            if (mapLock <= 800 - 10 && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                mapLock += 10;
            }
        }

        DrawRectangle(0, 0, 800, 1000, YELLOW);
        DrawRectangle(800, 60, 35, 35, WHITE);
        if (IsMouseInRange(800, 800 + 35, 60, 60 + 35))
        {
            DrawRectangle(800, 60, 35, 35, GRAY);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                mapLock = 0;
                *countryList = false;
            }
        }
    }
}