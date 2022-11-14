#include "Functions.h"

void Settings(bool* areSettingsOpen, bool* isMenuOpen, bool* openMap, int* countryNumber, int* questionsNumberCounter,
              bool* isQuizOpened, int* randomQuestion, bool* isAnswered, bool* isEscapeReleased, float* musicVolume, float* soundVolume,
              AllTextures textures, Font font)
{
    DrawTexture(textures.settingsIcon, 5, 5, WHITE);
    if (IsMouseInRange(5, 45, 5, 45))
    {
        DrawTexture(textures.settingsIcon, 5, 5, GRAY);
    }
    OpenSettings(areSettingsOpen, isMenuOpen, openMap, countryNumber, questionsNumberCounter, isQuizOpened, randomQuestion, isAnswered,
                 isEscapeReleased, musicVolume, soundVolume, textures, font);
    CloseSetting(areSettingsOpen, isEscapeReleased, textures);
}

void OpenSettings(bool* areSettingsOpen, bool* isMenuOpen, bool* openMap, int* countryNumber, int* questionsNumberCounter,
                  bool* isQuizOpened, int* randomQuestion, bool* isAnswered, bool* isEscapeReleased, float* musicVolume, float* soundVolume,
                  AllTextures textures, Font font)
{
    if (*areSettingsOpen || (IsMouseInRange(0, 40, 0, 40) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || IsKeyPressed(KEY_ESCAPE))
    {
        if (!*areSettingsOpen)
        {
            PlaySoundMulti(textures.clickSound);
        }
        DrawTexture(textures.settingsBox, 5, 50, WHITE);
        DrawTexture(textures.closeSettingsIcon, 450, 50, MAROON);
        BackToMenu(isMenuOpen, openMap, questionsNumberCounter, isQuizOpened, randomQuestion, isAnswered, textures, font);
        BackToMap(isMenuOpen, openMap, countryNumber, questionsNumberCounter, isQuizOpened, randomQuestion, isAnswered, textures, font);
        SetFPS(textures, font);
        ChangeMusicVolume(musicVolume, textures, font);
        ChangeSoundVolume(soundVolume, textures, font);
        *areSettingsOpen = true;
    }
}

void CloseSetting(bool* areSettingsOpen, bool* isEscapeReleased, AllTextures textures)
{
    if (*areSettingsOpen)
    {
        if (IsKeyPressed(KEY_ESCAPE) && *isEscapeReleased)
        {
            PlaySoundMulti(textures.clickSound);
            *areSettingsOpen = false;
            *isEscapeReleased = false;
        }

        if (IsKeyUp(KEY_ESCAPE))
        {
            *isEscapeReleased = true;
        }

        if (IsMouseInRange(450, 500, 50, 100))
        {
            DrawTexture(textures.closeSettingsIcon, 450, 50, RED);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                PlaySoundMulti(textures.clickSound);
                *areSettingsOpen = false;
                *isEscapeReleased = false;
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

int showMusicVolume = 10;
void ChangeMusicVolume(float* musicVolume, AllTextures textures, Font font)
{
    SetMusicVolume(textures.menuMusic, *musicVolume);

    DrawTextEx(font, "Music Volume:", VecPos(60, 180), 30, 4, BLACK);

    DrawTexture(textures.leftArrow, 300, 170, WHITE);
    DrawTextEx(font, TextFormat("%2i", showMusicVolume), VecPos(360, 180), 30, 4, BLACK);
    DrawTexture(textures.rightArrow, 420, 170, WHITE);

    if (IsMouseInRange(300, 300 + 50, 170, 170 + 50))
    {
        DrawTexture(textures.leftArrow, 300, 170, LIGHTGRAY);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (*musicVolume >= 0.05)
            {
                PlaySoundMulti(textures.clickSound);
                *musicVolume -= 0.05;
                showMusicVolume -= 5;
            }
            else
            {
                PlaySoundMulti(textures.clickSound);
                *musicVolume = 0;
                showMusicVolume = 0;
            }
        }
    }

    if (IsMouseInRange(420, 420 + 50, 170, 170 + 50))
    {
        DrawTexture(textures.rightArrow, 420, 170, LIGHTGRAY);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && *musicVolume < 1.0)
        {
            PlaySoundMulti(textures.clickSound);
            *musicVolume += 0.05;
            showMusicVolume += 5;
        }
    }
}

int showSoundVolume = 10;

void ChangeSoundVolume(float* soundVolume, AllTextures textures, Font font)
{
    SetSoundVolume(textures.clickSound, *soundVolume);

    DrawTextEx(font, "Sound Volume:", VecPos(60, 280), 30, 4, BLACK);

    DrawTexture(textures.leftArrow, 300, 270, WHITE);
    DrawTextEx(font, TextFormat("%2i", showSoundVolume), VecPos(360, 280), 30, 4, BLACK);
    DrawTexture(textures.rightArrow, 420, 270, WHITE);

    if (IsMouseInRange(300, 300 + 50, 270, 270 + 50))
    {
        DrawTexture(textures.leftArrow, 300, 270, LIGHTGRAY);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (*soundVolume >= 0.05)
            {
                PlaySoundMulti(textures.clickSound);
                *soundVolume -= 0.05;
                showSoundVolume -= 5;
            }
            else
            {
                PlaySoundMulti(textures.clickSound);
                *soundVolume = 0;
                showSoundVolume = 0;
            }
        }
    }

    if (IsMouseInRange(420, 420 + 50, 270, 270 + 50))
    {
        DrawTexture(textures.rightArrow, 420, 270, LIGHTGRAY);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && *soundVolume < 1.0)
        {
            PlaySoundMulti(textures.clickSound);
            *soundVolume += 0.05;
            showSoundVolume += 5;
        }
    }
}

void BackToMenu(bool* isMenuOpen, bool* openMap, int* questionsNumberCounter, bool* isQuizOpened, int* randomQuestion,
                bool* isAnswered, AllTextures textures, Font font)
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
            *isAnswered = true;
            *randomQuestion = 0;
            *questionsNumberCounter = 0;
            *isQuizOpened = false;
            *isMenuOpen = true;
            *openMap = false;
        }
    }
}

void BackToMap(bool* isMenuOpen,bool* openMap, int* countryNumber, int* questionsNumberCounter, bool* isQuizOpened, int* randomQuestion,
               bool* isAnswered, AllTextures textures, Font font)
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
            *isAnswered = true;
            *randomQuestion = 0;
            *questionsNumberCounter = 0;
            *isQuizOpened = false;
            *isMenuOpen = false;
            *openMap = true;
            *countryNumber = 0;
        }
    }
}