#include "Main.h"
#include "Menu.h"

void Menu(SettingsS& settings, MenuS& menu, MapS& map, GameS& game, LockedCountries& lockedCountries, AllTextures textures, Font font)
{
    if (!menu.newGame)
    {
        if (menu.isMenuOpen)
        {
            UpdateMusicStream(textures.menuMusic);

            DrawMenuBackground(menu, textures);
            StartGame(menu.isMenuOpen, map, textures, font);
            NewGame(menu.newGame, settings, menu, textures, font);
            CloseGame(menu.isGameClosed, textures, font);
        }
    }
    else
    {
        UpdateMusicStream(textures.menuMusic);
        DrawMenuBackground(menu, textures);
        NewGameWarning(menu.newGame, settings, game, lockedCountries, textures, font);
    }
}

void DrawMenuBackground(MenuS& menu, AllTextures textures)
{   
    int currentFPS = GetFPS();
    static int counter = 0;
    static float frameTime = 0; 
    static bool framePosition = false;
    int updateVertical;
    int updateFrameTime = frameTime * 200;

    DrawTexture(textures.background, menu.BGX, 0, WHITE);
    DrawTexture(textures.background, menu.BGX + 1920, 0, WHITE);

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
        menu.BusY += 3;
        counter = 0;
    }
    
    if (menu.BusY == 596)
    {
        menu.BusY = 590;
        framePosition =!framePosition;
    }

    if (menu.BusY > 590)
    {
        DrawTexture(textures.menuCaravanMiddle, menu.BusX, menu.BusY, WHITE);
    }
    else
    {
        if (!framePosition)
        {
            DrawTexture(textures.menuCaravanLeft, menu.BusX, menu.BusY, WHITE);
        }
        else
        {
            DrawTexture(textures.menuCaravanRight, menu.BusX, menu.BusY, WHITE);
        }
    }

    menu.BGX -= updateFrameTime;
    if (menu.BGX <= -1920)
    {
        menu.BGX = 0;
    }

    menu.BusX += updateFrameTime;
    if (menu.BusX >= 1920)
    {
        menu.BusX = -650;
    }

    frameTime = GetFrameTime();
}

void StartGame(bool& isMenuOpen, MapS& map, AllTextures textures, Font font)
{
    DrawTexture(textures.startBlock, 676, 280, WHITE);
    DrawTextEx(font, "Start", VecPos(814, 316), 96, 4, BLACK);
    if (IsMouseInRange(676, 676 + 480, 280, 280 + 149))
    {
        DrawTextEx(font, "Start", VecPos(816, 310), 96, 4, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            PlaySoundMulti(textures.clickSound);
            map.countryNumber = 0;
            map.openMap = true;
            isMenuOpen = false;
        }
    }
}

void CloseGame(bool& isGameClosed, AllTextures textures, Font font)
{
    DrawTexture(textures.startBlock, 676, 660, WHITE);
    DrawTextEx(font, "Exit", VecPos(844, 696), 96, 4, BLACK);
    if (IsMouseInRange(676, 676 + 480, 660, 660 + 149))
    {
        DrawTextEx(font, "Exit", VecPos(846, 690), 96, 4, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            PlaySoundMulti(textures.clickSound);
            isGameClosed = true;
        }
    }
}

void NewGame(bool& newGame, SettingsS& settings, MenuS& menu, AllTextures textures, Font font)
{
    DrawTexture(textures.startBlock, 676, 470, WHITE);
    DrawTextEx(font, "New Game", VecPos(736, 506), 80, 4, BLACK);
    if (IsMouseInRange(676, 676 + 480, 470, 470 + 149))
    {
        DrawTextEx(font, "New Game", VecPos(738, 502), 80, 4, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            PlaySoundMulti(textures.clickSound);
            newGame = true;
        }
    }
}

void NewGameWarning(bool& newGame, SettingsS& settings, GameS& game, LockedCountries& lockedCountries, AllTextures textures, Font font)
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
            PlaySoundMulti(textures.clickSound);
            ResetValues(settings, game, lockedCountries);
            newGame = false;
        }
    }

    if (IsMouseInRange(540 + 500, 540 + 500 + 300, 520, 520 + 120))
    {
        DrawTextEx(font, "No", VecPos(540 + 500 + 136, 520 + 48), 34, 4, BLACK);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            PlaySoundMulti(textures.clickSound);
            newGame = false;
        }
    }
}

void ResetValues(SettingsS& settings, GameS& game, LockedCountries& lockedCountries)
{
    settings.musicVolume = 0.05;
    settings.soundVolume = 0.15;

    game.money = 600;
    game.quizCounter[0] = 0;
    game.quizCounter[1] = 0;
    game.quizCounter[2] = 0;
    game.quizCounter[3] = 0;
    game.quizCounter[4] = 0;
    game.quizCounter[5] = 0;
    game.quizCounter[6] = 0;
    game.quizCounter[7] = 0;
    game.quizCounter[8] = 0;

    lockedCountries.isSpainOpen = false;
    lockedCountries.isFranceOpen = false;
    lockedCountries.isItalyOpen = false;
    lockedCountries.isGermanyOpen = false;
    lockedCountries.isGreeceOpen = false;
    lockedCountries.isTurkeyOpen = false;
    lockedCountries.isUnitedKingdomOpen = false;
    lockedCountries.isNorwayOpen = false;
}