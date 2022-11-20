#include "Main.h"
#include "Settings.h"

void Settings(SettingsS& settings, FlyingCows& cows, MenuS& menu, MapS& map, GameS& game, AllTextures textures, Font font)
{
    DrawTexture(textures.settingsIcon, 5, 5, WHITE);
    if (IsMouseInRange(5, 45, 5, 45))
    {
        DrawTexture(textures.settingsIcon, 5, 5, GRAY);
    }
    OpenSettings(settings, cows, menu, map, game, textures, font);
    CloseSetting(settings, textures);
}

void OpenSettings(SettingsS& settings, FlyingCows& cows, MenuS& menu, MapS& map, GameS& game, AllTextures textures, Font font)
{
    if (settings.areSettingsOpen || (IsMouseInRange(0, 40, 0, 40) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || IsKeyPressed(KEY_ESCAPE))
    {
        if (!settings.areSettingsOpen)
        {
            PlaySoundMulti(textures.clickSound);
        }
        DrawTexture(textures.settingsBox, 5, 50, WHITE);
        DrawTexture(textures.closeSettingsIcon, 450, 50, MAROON);
        BackToMenu(menu.isMenuOpen, map, cows, game, textures, font);
        BackToMap(menu.isMenuOpen, map, cows, game, textures, font);
        SetFPS(textures, font);
        ChangeMusicVolume(settings.musicVolume, textures, font);
        ChangeSoundVolume(settings.soundVolume, textures, font);
        settings.areSettingsOpen = true;
    }
}

void CloseSetting(SettingsS &settings, AllTextures textures)
{
    if (settings.areSettingsOpen)
    {
        if (IsKeyPressed(KEY_ESCAPE) && settings.isEscapeReleased)
        {
            PlaySoundMulti(textures.clickSound);
            settings.areSettingsOpen = false;
            settings.isEscapeReleased = false;
        }

        if (IsKeyUp(KEY_ESCAPE))
        {
            settings.isEscapeReleased = true;
        }

        if (IsMouseInRange(450, 500, 50, 100))
        {
            DrawTexture(textures.closeSettingsIcon, 450, 50, RED);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySoundMulti(textures.clickSound);
                settings.areSettingsOpen = false;
                settings.isEscapeReleased = false;
            }
        }
    }
}

void SetFPS(AllTextures textures, Font font)
{
    DrawTextEx(font, "FPS Limit:", VecPos(60, 130), 30, 4, BLACK);
    DrawTextEx(font, "30", VecPos(220, 127), 30, 4, BLACK);
    DrawTextEx(font, "60", VecPos(290, 130), 30, 4, BLACK);
    DrawTextEx(font, "144", VecPos(370, 130), 30, 4, BLACK);

    if (IsMouseInRange(220, 220 + 50, 125, 125 + 30))
    {
        DrawTextEx(font, "30", VecPos(221, 125), 30, 4, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            PlaySoundMulti(textures.clickSound);
            SetTargetFPS(30);
        }
    }

    if (IsMouseInRange(290, 290 + 50, 128, 128 + 30))
    {
        DrawTextEx(font, "60", VecPos(291, 128), 30, 4, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            PlaySoundMulti(textures.clickSound);
            SetTargetFPS(60);
        }
    }

    if (IsMouseInRange(370, 370 + 50, 128, 128 + 30))
    {
        DrawTextEx(font, "144", VecPos(371, 128), 30, 4, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            PlaySoundMulti(textures.clickSound);
            SetTargetFPS(144);
        }
    }
}

void ChangeMusicVolume(double& musicVolume, AllTextures textures, Font font)
{
    static int showMusicVolume = musicVolume * 100;

    SetMusicVolume(textures.menuMusic, musicVolume);

    DrawTextEx(font, "Music Volume:", VecPos(60, 230), 30, 4, BLACK);

    DrawTexture(textures.leftArrow, 300, 220, WHITE);
    DrawTextEx(font, TextFormat("%2i", showMusicVolume), VecPos(360, 230), 30, 4, BLACK);
    DrawTexture(textures.rightArrow, 420, 220, WHITE);

    if (IsMouseInRange(300, 300 + 50, 220, 220 + 50))
    {
        DrawTexture(textures.leftArrow, 300, 220, LIGHTGRAY);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (musicVolume >= 0.05)
            {
                PlaySoundMulti(textures.clickSound);
                musicVolume -= 0.05;
                showMusicVolume -= 5;
            }
            else
            {
                PlaySoundMulti(textures.clickSound);
                musicVolume = 0;
                showMusicVolume = 0;
            }
        }
    }

    if (IsMouseInRange(420, 420 + 50, 220, 220 + 50))
    {
        DrawTexture(textures.rightArrow, 420, 220, LIGHTGRAY);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && musicVolume < 1.0)
        {
            PlaySoundMulti(textures.clickSound);
            musicVolume += 0.05;
            showMusicVolume += 5;
        }
    }
}

void ChangeSoundVolume(double& soundVolume, AllTextures textures, Font font)
{
    static int showSoundVolume = soundVolume * 100;

    SetSoundVolume(textures.clickSound, soundVolume);

    DrawTextEx(font, "Sound Volume:", VecPos(60, 330), 30, 4, BLACK);

    DrawTexture(textures.leftArrow, 300, 320, WHITE);
    DrawTextEx(font, TextFormat("%2i", showSoundVolume), VecPos(360, 330), 30, 4, BLACK);
    DrawTexture(textures.rightArrow, 420, 320, WHITE);

    if (IsMouseInRange(300, 300 + 50, 320, 320 + 50))
    {
        DrawTexture(textures.leftArrow, 300, 320, LIGHTGRAY);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (soundVolume >= 0.05)
            {
                PlaySoundMulti(textures.clickSound);
                soundVolume -= 0.05;
                showSoundVolume -= 5;
            }
            else
            {
                PlaySoundMulti(textures.clickSound);
                soundVolume = 0;
                showSoundVolume = 0;
            }
        }
    }

    if (IsMouseInRange(420, 420 + 50, 320, 320 + 50))
    {
        DrawTexture(textures.rightArrow, 420, 320, LIGHTGRAY);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && soundVolume < 1.0)
        {
            PlaySoundMulti(textures.clickSound);
            soundVolume += 0.05;
            showSoundVolume += 5;
        }
    }
}

void BackToMenu(bool& isMenuOpen, MapS& map, FlyingCows& cows, GameS& game, AllTextures textures, Font font)
{
    DrawTexture(textures.taskBox, 35, 440, WHITE);
    Vector2 pos = {58,468};
    DrawTextEx(font, "Back to Menu", pos, 25, 2, BLACK);
    if (IsMouseInRange(35, 35 + 210, 440, 440 + 80))
    {
        pos.y = 467;
        DrawTextEx(font, "Back to Menu", pos, 25, 2, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            PlaySoundMulti(textures.clickSound);
            isMenuOpen = true;

            game.isAnswered = true;
            game.isQuizOpened = false;
            game.gameWarning = false;
            game.isGameOpened = false;
            game.trueQuestionCounter = 0;

            map.openMap = false;
            map.countryList = false;
            map.countryWarning = false;

            game.randomQuestion = 0;
            game.questionsNumberCounter = 0;

            cows.CCWarning = false;
            cows.isCCOpen = false;
        }
    }
}

void BackToMap(bool& isMenuOpen, MapS& map, FlyingCows& cows, GameS& game, AllTextures textures, Font font)
{
    DrawTexture(textures.taskBox, 255, 440, WHITE);
    Vector2 pos = {287,468};
    DrawTextEx(font, "Back to Map", pos, 25, 2, BLACK);
    if (IsMouseInRange(255, 255 + 210, 440, 440 + 80))
    {
        pos.y = 467;
        DrawTextEx(font, "Back to Map", pos, 25, 2, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            PlaySoundMulti(textures.clickSound);
            isMenuOpen = false;

            game.isAnswered = true;
            game.isQuizOpened = false;
            game.gameWarning = false;
            game.isGameOpened = false;
            game.trueQuestionCounter = 0;

            map.openMap = true;

            game.randomQuestion = 0;
            game.questionsNumberCounter = 0;
            map.countryNumber = 0;

            cows.CCWarning = false;
            cows.isCCOpen = false;
        }
    }
}