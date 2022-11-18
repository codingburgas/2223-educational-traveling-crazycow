#include "Main.h"

void Menu(SettingsS& settings, MenuS& menu, MapS& map, AllTextures textures, Font font)
{
    if (menu.isMenuOpen)
    {
        UpdateMusicStream(textures.menuMusic);

        DrawMenuBackground(menu, textures);
        StartGame(menu.isMenuOpen, map, textures, font);
        CloseGame(menu.isGameClosed, textures, font);
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
            map.countryNumber = 0;
            map.openMap = true;
            isMenuOpen = false;
        }
    }
}

void CloseGame(bool& isGameClosed, AllTextures textures, Font font)
{
    DrawTexture(textures.startBlock, 676, 500, WHITE);
    DrawTextEx(font, "Exit", VecPos(844, 536), 96, 4, BLACK);
    if (IsMouseInRange(676, 676 + 480, 500, 500 + 149))
    {
        DrawTextEx(font, "Exit", VecPos(846, 530), 96, 4, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            PlaySoundMulti(textures.clickSound);
            isGameClosed = true;
        }
    }
}