#include "Functions.h"

void Game(bool* openMap, int* countryNumber, int* countryHover, bool* countryList, int* mapLocation, bool* areSettingsOpen,
          int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isMenuOpen, bool* isQuizOpened,
          bool* isAnswered, bool* isWarningOpen, AllTextures textures, Font font, Variables::LockedCountriesBooleans* lockedCountries)
{
    if (*countryNumber != 0 && !*isMenuOpen)
    {
        *openMap = false;
        OpenCountry(countryNumber, money, trueQuestionCounter, questionsNumberCounter, randomQuestion, isQuizOpened, isAnswered, textures, font);
    }

    if (*openMap)
    {
        OpenTheMap(mapLocation, countryHover, countryList, areSettingsOpen, textures);
        OpenCountries(countryNumber, countryHover, mapLocation, countryList, areSettingsOpen, money, isWarningOpen, textures, font, lockedCountries);
    }

        DrawTextEx(font, TextFormat("%2i", *money), VecPos(1810, 55), 32, 4, BLACK);
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
            DrawTexture(textures.rightArrow, 0, 60, LIGHTGRAY);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySoundMulti(textures.clickSound);
                *countryList = true;
            }
        }
    }
}

void OpenCountries(int* countryNumber, int* countryHover, int* mapLocation, bool* countryList, bool* areSettingsOpen, int* money,
                   bool* isWarningOpen, AllTextures textures, Font font, Variables::LockedCountriesBooleans* lockedCountries)
{
    if (*countryList)
    {
        MoveMap(mapLocation, textures);

        DrawTexture(textures.woodBox, 0, 0, WHITE);
        DrawTexture(textures.leftArrow, 805, 0, WHITE);

        ChooseCountry(countryNumber, countryHover, areSettingsOpen, money, isWarningOpen, textures, font, lockedCountries);

        if (IsMouseInRange(800, 800 + 50, 0, 50) && !*areSettingsOpen)
        {
            DrawTexture(textures.leftArrow, 805, 0, LIGHTGRAY);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySoundMulti(textures.clickSound);
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
        DrawTexture(textures.rightArrow, 1920 - 50, 0, LIGHTGRAY);
        if (*mapLocation >= mapMove && (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_RIGHT)))
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_RIGHT))
            {
                PlaySoundMulti(textures.clickSound);
            }
            *mapLocation -= mapMove;
        }
    }

    DrawTexture(textures.leftArrow, 1920 - 100, 0, WHITE);
    if (IsMouseInRange(1920 - 100, 1920 - 50, 0, 50) || IsKeyDown(KEY_LEFT))
    {
        DrawTexture(textures.leftArrow, 1920 - 100, 0, LIGHTGRAY);
        if (*mapLocation <= 800 - mapMove && (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_LEFT)))
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_LEFT))
            {
                PlaySoundMulti(textures.clickSound);
            }
            *mapLocation += mapMove;
        }
    }

    mapFrameTime = GetFrameTime();
}

void ChooseCountry(int* countryNumber, int* countryHover, bool* areSettingsOpen, int* money, bool* isWarningOpen, AllTextures textures, Font font,
                   Variables::LockedCountriesBooleans* lockedCountries)
{
    DrawCountry(font, "Bulgaria", 249, 36, 298, 86, 1, countryNumber, countryHover, areSettingsOpen,
                &lockedCountries->isBulgariaOpen, money, isWarningOpen, textures);

    DrawCountry(font, "Spain", 295, 136, 200, 86, 2, countryNumber, countryHover, areSettingsOpen,
                &lockedCountries->isSpainOpen, money, isWarningOpen, textures);

    DrawCountry(font, "France", 275, 236, 246, 76, 3, countryNumber, countryHover, areSettingsOpen,
                &lockedCountries->isFranceOpen, money, isWarningOpen, textures);

    DrawCountry(font, "Italy", 305, 336, 175, 76, 4, countryNumber, countryHover, areSettingsOpen,
                &lockedCountries->isItalyOpen, money, isWarningOpen, textures);

    DrawCountry(font, "Germany", 239, 436, 320, 86, 5, countryNumber, countryHover, areSettingsOpen,
                &lockedCountries->isGermanyOpen, money, isWarningOpen, textures);

    DrawCountry(font, "Turkey", 269, 536, 263, 83, 6, countryNumber, countryHover, areSettingsOpen,
                &lockedCountries->isTurkeyOpen, money, isWarningOpen, textures);

    DrawCountry(font, "Greece", 269, 630, 256, 70, 7, countryNumber, countryHover, areSettingsOpen,
                &lockedCountries->isGreeceOpen, money, isWarningOpen, textures);

    DrawCountry(font, "United Kingdom", 110, 732, 570, 83, 8, countryNumber, countryHover, areSettingsOpen,
                &lockedCountries->isUnitedKingdomOpen, money, isWarningOpen, textures);

    DrawCountry(font, "Norway", 255, 826, 279, 79, 9, countryNumber, countryHover, areSettingsOpen,
                &lockedCountries->isNorwayOpen, money, isWarningOpen, textures);
}

bool notEnoughMoney = false;
bool* saveLockedCountry;

void DrawCountry(Font font, const char* name, float x, float y, float lengthX, float lenghtY, int countryNum, int* countryNumber, int* countryHover,
                 bool* areSettingsOpen, bool* lockedCountry, int* money, bool* isWarningOpen, AllTextures textures)
{
    DrawTextEx(font, name, VecPos(x, y), 80, 6, BLACK);

    if (*lockedCountry)
    {
        if (IsMouseInRange(x, x + lengthX, y, y + lenghtY) && !*areSettingsOpen && !*isWarningOpen)
        {
            *countryHover = countryNum;
            DrawTextEx(font, name, VecPos(x + 2, y - 4), 80, 6, BLACK);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySoundMulti(textures.clickSound);
                *countryNumber = countryNum;
            }
        }
    }
    else
    {
        DrawTexture(textures.chain, 5, y + 12, WHITE);
        if (IsMouseInRange(376, 376 + 70, y + 10, y + 90) && !*areSettingsOpen && !*isWarningOpen)
        {
            DrawTexture(textures.chain, 5, y + 12, LIGHTGRAY);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySoundMulti(textures.clickSound);
                *isWarningOpen = true;
                saveLockedCountry = lockedCountry;
                notEnoughMoney = false;
            }
        }

        if (*isWarningOpen)
        {
            OpenWarning(saveLockedCountry, isWarningOpen, money, textures, font);
        }
    }
}

void OpenWarning(bool* saveLockedCountry, bool* isWarningOpen, int* money, AllTextures textures, Font font)
{
    if (!notEnoughMoney)
    {
        DrawTexture(textures.quizBox, 0, 0, WHITE);
        DrawTextEx(font, "Are you sure?", VecPos(560, 340), 120, 8, BLACK);

        DrawTexture(textures.answerBlock, 540, 520, WHITE);
        DrawTextEx(font, "Yes", VecPos(540 + 120, 520 + 50), 34, 4, BLACK);

        DrawTexture(textures.answerBlock, 540 + 500, 520, WHITE);
        DrawTextEx(font, "No", VecPos(540 + 500 + 134, 520 + 50), 34, 4, BLACK);

        if (IsMouseInRange(540, 540 + 300, 520, 520 + 120))
        {
            DrawTextEx(font, "Yes", VecPos(540 + 122, 520 + 48), 34, 4, BLACK);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                if (*money >= 200)
                {
                    PlaySoundMulti(textures.clickSound);
                    *saveLockedCountry = true;
                    *money -= 200;
                    *isWarningOpen = false;
                }
                else
                {
                    PlaySoundMulti(textures.clickSound);
                    notEnoughMoney = true;
                }
            }
        }

        if (IsMouseInRange(540 + 500, 540 + 500 + 300, 520, 520 + 120))
        {
            DrawTextEx(font, "No", VecPos(540 + 500 + 136, 520 + 48), 34, 4, BLACK);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySoundMulti(textures.clickSound);
                *isWarningOpen = false;
            }
        }
    }
    else
    {
        DrawTexture(textures.quizBox, 0, 0, WHITE);
        DrawTextEx(font, "Not enough", VecPos(680, 300), 100, 8, BLACK);
        DrawTextEx(font, "money!", VecPos(790, 400), 100, 8, BLACK);

        DrawTexture(textures.answerBlock, 800, 560, WHITE);
        DrawTextEx(font, "Ok", VecPos(800 + 100, 560 + 30), 60, 6, BLACK);
        if (IsMouseInRange(800, 800 + 300, 560, 560 + 120))
        {
            DrawTextEx(font, "Ok", VecPos(800 + 102, 560 + 26), 60, 6, BLACK);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySoundMulti(textures.clickSound);
                *isWarningOpen = false;
            }
        }
    }
}