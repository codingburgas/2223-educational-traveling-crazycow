#include "Functions.h"

void Settings(bool* areSettingsOpen, bool* isMenuOpen, bool* openMap, int* countryNumber, int* questionsNumberCounter,
              bool* isQuizOpened, int* randomQuestion, bool* isAnswered, AllTextures textures, Font font)
{
    DrawTexture(textures.settingsIcon, 5, 5, WHITE);
    if (IsMouseInRange(5, 45, 5, 45))
    {
        DrawTexture(textures.settingsIcon, 5, 5, GRAY);
    }
    OpenSettings(areSettingsOpen, isMenuOpen, openMap, countryNumber, questionsNumberCounter, isQuizOpened, randomQuestion, isAnswered,
                textures, font);
    CloseSetting(areSettingsOpen, textures);
}

void OpenSettings(bool* areSettingsOpen, bool* isMenuOpen, bool* openMap, int* countryNumber, int* questionsNumberCounter,
                  bool* isQuizOpened, int* randomQuestion, bool* isAnswered, AllTextures textures, Font font)
{
    if (*areSettingsOpen || (IsMouseInRange(0, 40, 0, 40) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || IsKeyPressed(KEY_ESCAPE))
    {
        DrawTexture(textures.settingsBox, 5, 50, WHITE);
        DrawTexture(textures.closeSettingsIcon, 450, 50, MAROON);
        BackToMenu(isMenuOpen, openMap, questionsNumberCounter, isQuizOpened, randomQuestion, isAnswered, textures, font);
        BackToMap(openMap, countryNumber, questionsNumberCounter, isQuizOpened, randomQuestion, isAnswered, textures, font);
        SetFPS(textures, font);
        *areSettingsOpen = true;
    }
}

void CloseSetting(bool* areSettingsOpen, AllTextures textures)
{
    if (*areSettingsOpen && IsMouseInRange(450, 500, 50, 100))
    {
        DrawTexture(textures.closeSettingsIcon, 450, 50, RED);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            *areSettingsOpen = false;
        }
    }
}

void SetFPS(AllTextures textures, Font font)
{
    DrawTextEx(font, "FPS Limit:", VecPos(40, 80), 30, 4, BLACK);
    DrawTextEx(font, "60", VecPos(210, 80), 30, 4, BLACK);
    DrawTextEx(font, "144", VecPos(280, 80), 30, 4, BLACK);
    DrawTextEx(font, "240", VecPos(360, 80), 30, 4, BLACK);

    if (IsMouseInRange(210, 210 + 50, 80, 80 + 30))
    {
        DrawTextEx(font, "60", VecPos(211, 78), 30, 4, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            SetTargetFPS(60);
        }
    }

    if (IsMouseInRange(280, 280 + 50, 80, 80 + 30))
    {
        DrawTextEx(font, "144", VecPos(281, 78), 30, 4, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            SetTargetFPS(144);
        }
    }

    if (IsMouseInRange(360, 360 + 50, 80, 80 + 30))
    {
        DrawTextEx(font, "240", VecPos(361, 78), 30, 4, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            SetTargetFPS(240);
        }
    }
}

void BackToMenu(bool* isMenuOpen, bool* openMap, int* questionsNumberCounter, bool* isQuizOpened, int* randomQuestion,
                bool* isAnswered, AllTextures textures, Font font)
{
    DrawTexture(textures.taskBox, 35, 440, WHITE);
    Vector2 pos;
    pos.x = 58;
    pos.y = 468;
    DrawTextEx(font, "Back to Menu", pos, 25, 2, BLACK);
    if (IsMouseInRange(35, 35 + 210, 440, 440 + 80))
    {
        pos.y = 467;
        DrawTextEx(font, "Back to Menu", pos, 25, 2, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            *isAnswered = true;
            *randomQuestion = 0;
            *questionsNumberCounter = 0;
            *isQuizOpened = false;
            *isMenuOpen = true;
            *openMap = false;
        }
    }
}

void BackToMap(bool* openMap, int* countryNumber, int* questionsNumberCounter, bool* isQuizOpened, int* randomQuestion,
               bool* isAnswered, AllTextures textures, Font font)
{
    DrawTexture(textures.taskBox, 255, 440, WHITE);
    Vector2 pos;
    pos.x = 287;
    pos.y = 468;
    DrawTextEx(font, "Back to Map", pos, 25, 2, BLACK);
    if (IsMouseInRange(255, 255 + 210, 440, 440 + 80))
    {
        pos.y = 467;
        DrawTextEx(font, "Back to Map", pos, 25, 2, BLACK);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            *isAnswered = true;
            *randomQuestion = 0;
            *questionsNumberCounter = 0;
            *isQuizOpened = false;
            *openMap = true;
            *countryNumber = 0;
        }
    }
}