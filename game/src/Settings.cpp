#include "Functions.h"

void OpenSettings(bool* areSettingsOpen, bool* isMenuOpen, bool* chooseCountry, AllTextures textures)
{
    if (*areSettingsOpen || (IsMouseInRange(0, 40, 0, 40) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true))
    {
        DrawTexture(textures.settingsBox, 5, 50, WHITE);
        DrawTexture(textures.closeSettingsIcon, 450, 50, MAROON);
        BackToMenu(isMenuOpen, chooseCountry, textures);
        *areSettingsOpen = true;
    }
}

void CloseSetting(bool* areSettingsOpen, AllTextures textures)
{
    if (*areSettingsOpen && (IsMouseInRange(450, 500, 50, 100)))
    {
        DrawTexture(textures.closeSettingsIcon, 450, 50, RED);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true)
        {
            *areSettingsOpen = false;
        }
    }
}

void BackToMenu(bool* isMenuOpen, bool* chooseCountry, AllTextures textures)
{
    DrawTexture(textures.taskBox, 35, 440, WHITE);
    DrawText("Back to Menu", 55, 465, 26, LIME);
    if (IsMouseInRange(35, 35 + 210, 440, 440 + 80))
    {
        DrawText("Back to Menu", 55, 462, 26, GREEN);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true)
        {
            *isMenuOpen = true;
            *chooseCountry = false;
        }
    }
}