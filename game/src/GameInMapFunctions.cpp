#include "Main.h"
#include "GameInMap.h"
#include "GameInCountry.h"

void Game(SettingsS& settings, MenuS& menu, MapS& map, GameS& game, LockedCountries& lockedCountries, AllTextures textures, Font font)

{
    if (map.countryNumber != 0 && !menu.isMenuOpen)
    {
        map.openMap = false;
        OpenCountry(map.countryNumber, game, textures, font);
    }

    if (map.openMap)
    {
        OpenTheMap(settings.areSettingsOpen, map, textures);
        OpenCountries(settings.areSettingsOpen, game.money, map, textures, font, lockedCountries);
    }

        DrawTextEx(font, TextFormat("%2i", game.money), VecPos(1810, 55), 32, 4, BLACK);
        DrawTexture(textures.wheatIcon, 1920 - 36, 55, WHITE);
    
}

void OpenTheMap(bool& areSettingsOpen, MapS& map, AllTextures textures)
{
    switch (map.countryHover)
    {
    case 1:
        DrawTexture(textures.europeBulgaria, map.mapLocation, 0, WHITE);
        map.countryHover = 0;
        break;
    case 2:
        DrawTexture(textures.europeSpain, map.mapLocation, 0, WHITE);
        map.countryHover = 0;
        break;
    case 3:
        DrawTexture(textures.europeFrance, map.mapLocation, 0, WHITE);
        map.countryHover = 0;
        break;
    case 4:
        DrawTexture(textures.europeItaly, map.mapLocation, 0, WHITE);
        map.countryHover = 0;
        break;
    case 5:
        DrawTexture(textures.europeGermany, map.mapLocation, 0, WHITE);
        map.countryHover = 0;
        break;
    case 6:
        DrawTexture(textures.europeTurkey, map.mapLocation, 0, WHITE);
        map.countryHover = 0;
        break;
    case 7:
        DrawTexture(textures.europeGreece, map.mapLocation, 0, WHITE);
        map.countryHover = 0;
        break;
    case 8:
        DrawTexture(textures.europeEngland, map.mapLocation, 0, WHITE);
        map.countryHover = 0;
        break;
    case 9:
        DrawTexture(textures.europeNorway, map.mapLocation, 0, WHITE);
        map.countryHover = 0;
        break;
    default:
        DrawTexture(textures.europeMap, map.mapLocation, 0, WHITE);
        break;
    }

    DrawTexture(textures.rightArrow, 0, 60, WHITE);
    if (!areSettingsOpen)
    {
        if (IsMouseInRange(0, 50, 60, 60 + 50))
        {
            DrawTexture(textures.rightArrow, 0, 60, LIGHTGRAY);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySoundMulti(textures.clickSound);
                map.countryList = true;
            }
        }
    }
}

void OpenCountries(bool& areSettingsOpen, int& money, MapS& map, AllTextures textures, Font font, LockedCountries& lockedCountries)
{
    if (map.countryList)
    {
        MoveMap(map.mapLocation, textures);

        DrawTexture(textures.woodBox, 0, 0, WHITE);
        DrawTexture(textures.leftArrow, 805, 0, WHITE);

        ChooseCountry(areSettingsOpen, money, map, textures, font, lockedCountries);

        if (IsMouseInRange(800, 800 + 50, 0, 50) && !areSettingsOpen)
        {
            DrawTexture(textures.leftArrow, 805, 0, LIGHTGRAY);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySoundMulti(textures.clickSound);
                map.mapLocation = 0;
                map.countryList = false;
            }
        }
    }
}

void MoveMap(int& mapLocation, AllTextures textures)
{
    int currentFPS = GetFPS();
    int mapMove = 0;
    static float mapFrameTime = 0;

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
        if (mapLocation >= mapMove && (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_RIGHT)))
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_RIGHT))
            {
                PlaySoundMulti(textures.clickSound);
            }
            mapLocation -= mapMove;
        }
    }

    DrawTexture(textures.leftArrow, 1920 - 100, 0, WHITE);
    if (IsMouseInRange(1920 - 100, 1920 - 50, 0, 50) || IsKeyDown(KEY_LEFT))
    {
        DrawTexture(textures.leftArrow, 1920 - 100, 0, LIGHTGRAY);
        if (mapLocation <= 800 - mapMove && (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_LEFT)))
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_LEFT))
            {
                PlaySoundMulti(textures.clickSound);
            }
            mapLocation += mapMove;
        }
    }

    mapFrameTime = GetFrameTime();
}

void ChooseCountry(bool& areSettingsOpen, int& money, MapS& map, AllTextures textures, Font font, LockedCountries& lockedCountries)
{
    DrawCountry("Bulgaria", 249, 36, 298, 86, 1, map, areSettingsOpen, money, lockedCountries.isBulgariaOpen, textures, font);

    DrawCountry("Spain", 295, 136, 200, 86, 2, map, areSettingsOpen, money, lockedCountries.isSpainOpen, textures, font);

    DrawCountry("France", 275, 236, 246, 76, 3, map, areSettingsOpen, money, lockedCountries.isFranceOpen, textures, font);

    DrawCountry("Italy", 305, 336, 175, 76, 4, map, areSettingsOpen, money, lockedCountries.isItalyOpen, textures, font);

    DrawCountry("Germany", 239, 436, 320, 86, 5, map, areSettingsOpen, money, lockedCountries.isGermanyOpen, textures, font);

    DrawCountry("Turkey", 269, 536, 263, 83, 6, map, areSettingsOpen, money, lockedCountries.isTurkeyOpen, textures, font);

    DrawCountry("Greece", 269, 630, 256, 70, 7, map, areSettingsOpen, money, lockedCountries.isGreeceOpen, textures, font);

    DrawCountry("United Kingdom", 110, 732, 570, 83, 8, map, areSettingsOpen, money, lockedCountries.isUnitedKingdomOpen, textures, font);

    DrawCountry("Norway", 255, 826, 279, 79, 9, map, areSettingsOpen, money, lockedCountries.isNorwayOpen, textures, font);
}

void DrawCountry(const char* name, int x, int y, int lengthX, int lenghtY, int countryNum, MapS& map,
    bool& areSettingsOpen, int& money, bool& lockedCountry, AllTextures textures, Font font)
{
    static bool* saveLockedCountry;

    DrawTextEx(font, name, VecPos(x, y), 80, 6, BLACK);

    if (lockedCountry)
    {
        if (IsMouseInRange(x, x + lengthX, y, y + lenghtY) && !areSettingsOpen && !map.countryWarning)
        {
            map.countryHover = countryNum;
            DrawTextEx(font, name, VecPos(x + 2, y - 4), 80, 6, BLACK);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySoundMulti(textures.clickSound);
                map.countryNumber = countryNum;
            }
        }
    }
    else
    {
        DrawTexture(textures.chain, 5, y + 12, WHITE);
        if (IsMouseInRange(376, 376 + 70, y + 10, y + 90) && !areSettingsOpen && !map.countryWarning)
        {
            DrawTexture(textures.chain, 5, y + 12, LIGHTGRAY);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySoundMulti(textures.clickSound);
                map.countryWarning = true;
                saveLockedCountry = &lockedCountry;
                map.notEnoughMoney = false;
            }
        }

        if (map.countryWarning)
        {
            OpenWarning(saveLockedCountry, money, map, textures, font);
        }
    }
}

void OpenWarning(bool* saveLockedCountry, int& money, MapS& map, AllTextures textures, Font font)
{
    if (!map.notEnoughMoney)
    {
        DrawTexture(textures.quizBox, 0, 0, WHITE);
        DrawTextEx(font, "Are you sure?", VecPos(560, 260), 120, 8, BLACK);

        DrawTextEx(font, "Price - 200", VecPos(810, 420), 40, 6, BLACK);
        DrawTexture(textures.wheatIcon, 1060, 420, WHITE);

        DrawTexture(textures.answerBlock, 540, 520, WHITE);
        DrawTextEx(font, "Yes", VecPos(540 + 120, 520 + 50), 34, 4, BLACK);

        DrawTexture(textures.answerBlock, 540 + 500, 520, WHITE);
        DrawTextEx(font, "No", VecPos(540 + 500 + 134, 520 + 50), 34, 4, BLACK);

        if (IsMouseInRange(540, 540 + 300, 520, 520 + 120))
        {
            DrawTextEx(font, "Yes", VecPos(540 + 122, 520 + 48), 34, 4, BLACK);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                if (money >= 200)
                {
                    PlaySoundMulti(textures.clickSound);
                    *saveLockedCountry = true;
                    money -= 200;
                    map.unlockedCountries++;
                    map.countryWarning = false;
                }
                else
                {
                    PlaySoundMulti(textures.clickSound);
                    map.notEnoughMoney = true;
                }
            }
        }

        if (IsMouseInRange(540 + 500, 540 + 500 + 300, 520, 520 + 120))
        {
            DrawTextEx(font, "No", VecPos(540 + 500 + 136, 520 + 48), 34, 4, BLACK);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySoundMulti(textures.clickSound);
                map.countryWarning = false;
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
                map.countryWarning = false;
            }
        }
    }
}