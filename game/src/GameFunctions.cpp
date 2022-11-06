#include "Functions.h"

void Game(bool* openMap, int* countryNumber, int* countryHover, bool* countryList, int* mapLocation, AllTextures textures, Font font)
{
    if (*openMap)
    {
        OpenTheMap(mapLocation, countryHover, countryList, textures);
        OpenCountries(countryNumber, countryHover, mapLocation, countryList, textures, font);
    }
}

void OpenTheMap(int* mapLocation, int* countryHover, bool* countryList, AllTextures textures)
{
    switch (*countryHover)
    {
    case 1:
        DrawTexture(textures.europeBulgaria, *mapLocation, 0, WHITE);
        *countryHover = 0;
        break;
    case 2:
        DrawTexture(textures.europeSpain, *mapLocation, 0, WHITE);
        *countryHover = 0;
        break;
    case 3:
        DrawTexture(textures.europeFrance, *mapLocation, 0, WHITE);
        *countryHover = 0;
        break;
    case 4:
        DrawTexture(textures.europeItaly, *mapLocation, 0, WHITE);
        *countryHover = 0;
        break;
    case 5:
        DrawTexture(textures.europeGermany, *mapLocation, 0, WHITE);
        *countryHover = 0;
        break;
    case 6:
        DrawTexture(textures.europeTurkey, *mapLocation, 0, WHITE);
        *countryHover = 0;
        break;
    case 7:
        DrawTexture(textures.europeGreece, *mapLocation, 0, WHITE);
        *countryHover = 0;
        break;
    case 8:
        DrawTexture(textures.europeEngland, *mapLocation, 0, WHITE);
        *countryHover = 0;
        break;
    case 9:
        DrawTexture(textures.europeNorway, *mapLocation, 0, WHITE);
        *countryHover = 0;
        break;
    default:
        DrawTexture(textures.europeMap, *mapLocation, 0, WHITE);
    }

    DrawTexture(textures.rightArrow, 0, 60, WHITE);
    if (IsMouseInRange(0, 50, 60, 60 + 50))
    {
        DrawTexture(textures.rightArrow, 0, 60, RAYWHITE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            *countryList = true;
        }
    }
}

void OpenCountries(int* countryNumber, int* countryHover, int* mapLocation, bool* countryList, AllTextures textures, Font font)
{
    if (*countryList)
    {
        MoveMap(mapLocation, textures);

        DrawTexture(textures.woodBox, 0, 0, WHITE);
        DrawTexture(textures.leftArrow, 800, 0, WHITE);

        ChooseCountry(countryNumber, countryHover, textures, font);

        if (IsMouseInRange(800, 800 + 50, 0, 50))
        {
            DrawTexture(textures.leftArrow, 800, 0, RAYWHITE);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                *mapLocation = 0;
                *countryList = false;
            }
        }
    }
}

void MoveMap(int* mapLocation, AllTextures textures)
{
    DrawTexture(textures.rightArrow, 1920 - 50, 0, WHITE);
    if (IsMouseInRange(1920 - 50, 1920, 0, 50) || IsKeyDown(KEY_RIGHT))
    {
        DrawTexture(textures.rightArrow, 1920 - 50, 0, RAYWHITE);
        if (*mapLocation >= 10 && (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_RIGHT)))
        {
            *mapLocation -= 10;
        }
    }

    DrawTexture(textures.leftArrow, 1920 - 100, 0, WHITE);
    if (IsMouseInRange(1920 - 100, 1920 - 50, 0, 50) || IsKeyDown(KEY_LEFT))
    {
        DrawTexture(textures.leftArrow, 1920 - 100, 0, RAYWHITE);
        if (*mapLocation <= 800 - 10 && (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_LEFT)))
        {
            *mapLocation += 10;
        }
    }
}

void ChooseCountry(int* countryNumber, int* countryHover, AllTextures textures, Font font)
{
    DrawCountry(font, "Bulgaria", 230, 36, 298, 86, 1, countryNumber, countryHover);
    DrawCountry(font, "Spain", 276, 136, 200, 86, 2, countryNumber, countryHover);
    DrawCountry(font, "France", 256, 236, 246, 76, 3, countryNumber, countryHover);
    DrawCountry(font, "Italy", 286, 336, 200, 76, 4, countryNumber, countryHover);
    DrawCountry(font, "Germany", 220, 436, 320, 86, 5, countryNumber, countryHover);
    DrawCountry(font, "Turkey", 250, 536, 266, 86, 6, countryNumber, countryHover);
    DrawCountry(font, "Greece", 250, 630, 264, 76, 7, countryNumber, countryHover);
    DrawCountry(font, "England", 234, 732, 286, 86, 8, countryNumber, countryHover);
    DrawCountry(font, "Norway", 236, 826, 290, 86, 9, countryNumber, countryHover);
}

void DrawCountry(Font font, const char* name, int x, int y, int lengthX, int lenghtY, int countryNum, int* countryNumber, int* countryHover)
{
    Vector2 pos;
    pos.x = x;
    pos.y = y;
    DrawTextEx(font, name, pos, 80, 6, BLACK);
    if (IsMouseInRange(x, x + lengthX, y, y + lenghtY))
    {
        *countryHover = countryNum;
        pos.x = x + 2;
        pos.y = y - 4;
        DrawTextEx(font, name, pos, 80, 6, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            *countryNumber = countryNum;
        }
    }
}