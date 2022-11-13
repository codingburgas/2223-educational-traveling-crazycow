#include "Functions.h"

void Game(bool* openMap, int* countryNumber, int* countryHover, bool* countryList, int* mapLocation, bool* areSettingsOpen,
          int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isMenuOpen, bool* isQuizOpened,
          bool* isAnswered, AllTextures textures, Font font, Variables::LockedCountriesBooleans* lockedCountries)
{
    if (*countryNumber != 0 && !*isMenuOpen)
    {
        *openMap = false;
        OpenCountry(countryNumber, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isQuizOpened, isAnswered, textures, font);
    }

    if (*openMap)
    {
        OpenTheMap(mapLocation, countryHover, countryList, areSettingsOpen, textures);
        OpenCountries(countryNumber, countryHover, mapLocation, countryList, areSettingsOpen, textures, font, lockedCountries);
    }

        DrawTextEx(font, TextFormat("%02i", *money), VecPos(1830, 55), 32, 4, GRAY);
        DrawTexture(textures.wheatIcon, 1920 - 36, 55, WHITE);
    
}

void OpenTheMap(int* mapLocation, int* countryHover, bool* countryList, bool* areSettingsOpen, AllTextures textures)
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
        break;
    }

    DrawTexture(textures.rightArrow, 0, 60, WHITE);
    if (!*areSettingsOpen)
    {
        if (IsMouseInRange(0, 50, 60, 60 + 50))
        {
            DrawTexture(textures.rightArrow, 0, 60, RAYWHITE);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                *countryList = true;
            }
        }
    }
}

void OpenCountries(int* countryNumber, int* countryHover, int* mapLocation, bool* countryList, bool* areSettingsOpen, AllTextures textures, Font font,
                   Variables::LockedCountriesBooleans* lockedCountries)
{
    if (*countryList)
    {
        MoveMap(mapLocation, textures);

        DrawTexture(textures.woodBox, 0, 0, WHITE);
        DrawTexture(textures.leftArrow, 805, 0, WHITE);

        ChooseCountry(countryNumber, countryHover, areSettingsOpen, textures, font, lockedCountries);

        if (IsMouseInRange(800, 800 + 50, 0, 50) && !*areSettingsOpen)
        {
            DrawTexture(textures.leftArrow, 805, 0, RAYWHITE);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                *mapLocation = 0;
                *countryList = false;
            }
        }
    }
}

float mapFrameTime = 0;

void MoveMap(int* mapLocation, AllTextures textures)
{
    int currentFPS = GetFPS();
    int mapMove = 0;
    int updatemapFrameTime = mapFrameTime * 200;

    if (currentFPS > 60)
    {
        mapMove = mapFrameTime + 3;
    }
    else if (currentFPS <= 30)
    {
        mapMove = mapFrameTime + 16;
    }
    else
    {
        mapMove = mapFrameTime + 8;
    }

    DrawTexture(textures.rightArrow, 1920 - 50, 0, WHITE);
    if (IsMouseInRange(1920 - 50, 1920, 0, 50) || IsKeyDown(KEY_RIGHT))
    {
        DrawTexture(textures.rightArrow, 1920 - 50, 0, RAYWHITE);
        if (*mapLocation >= mapMove && (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_RIGHT)))
        {
            *mapLocation -= mapMove;
        }
    }

    DrawTexture(textures.leftArrow, 1920 - 100, 0, WHITE);
    if (IsMouseInRange(1920 - 100, 1920 - 50, 0, 50) || IsKeyDown(KEY_LEFT))
    {
        DrawTexture(textures.leftArrow, 1920 - 100, 0, RAYWHITE);
        if (*mapLocation <= 800 - mapMove && (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_LEFT)))
        {
            *mapLocation += mapMove;
        }
    }

    mapFrameTime = GetFrameTime();
}

void ChooseCountry(int* countryNumber, int* countryHover, bool* areSettingsOpen, AllTextures textures, Font font,
                   Variables::LockedCountriesBooleans* lockedCountries)
{
    DrawCountry(font, "Bulgaria", 249, 36, 298, 86, 1, countryNumber, countryHover, areSettingsOpen, &lockedCountries->isBulgariaOpen);
    DrawCountry(font, "Spain", 295, 136, 200, 86, 2, countryNumber, countryHover, areSettingsOpen, &lockedCountries->isSpainOpen);
    DrawCountry(font, "France", 275, 236, 246, 76, 3, countryNumber, countryHover, areSettingsOpen, &lockedCountries->isFranceOpen);
    DrawCountry(font, "Italy", 305, 336, 175, 76, 4, countryNumber, countryHover, areSettingsOpen, &lockedCountries->isItalyOpen);
    DrawCountry(font, "Germany", 239, 436, 320, 86, 5, countryNumber, countryHover, areSettingsOpen, &lockedCountries->isGermanyOpen);
    DrawCountry(font, "Turkey", 269, 536, 263, 83, 6, countryNumber, countryHover, areSettingsOpen, &lockedCountries->isTurkeyOpen);
    DrawCountry(font, "Greece", 269, 630, 256, 70, 7, countryNumber, countryHover, areSettingsOpen, &lockedCountries->isGreeceOpen);
    DrawCountry(font, "United Kingdom", 110, 732, 570, 83, 8, countryNumber, countryHover, areSettingsOpen, &lockedCountries->isUnitedKingdomOpen);
    DrawCountry(font, "Norway", 255, 826, 279, 79, 9, countryNumber, countryHover, areSettingsOpen, &lockedCountries->isNorwayOpen);
}

void DrawCountry(Font font, const char* name, float x, float y, float lengthX, float lenghtY, int countryNum, int* countryNumber, int* countryHover,
                 bool* areSettingsOpen, bool* lockedCountry)
{
    DrawTextEx(font, name, VecPos(x, y), 80, 6, BLACK);

    if (*lockedCountry)
    {
        if (IsMouseInRange(x, x + lengthX, y, y + lenghtY) && !*areSettingsOpen)
        {
            *countryHover = countryNum;
            DrawTextEx(font, name, VecPos(x + 2, y - 4), 80, 6, BLACK);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                *countryNumber = countryNum;
            }
        }
    }
    else
    {
        DrawRectangle(x, y, 80, 80, WHITE);
        if (IsMouseInRange(x, x + 80, y, y + 80))
        {
            DrawRectangle(x, y, 80, 80, GRAY);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                *lockedCountry = true;
            }
        }
    }
}