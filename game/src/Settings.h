#pragma once
#include "Main.h"

void OpenSettings(bool* areSettingsOpen, bool* isMenuOpen, bool* openMap, int* countryNumber, int* questionsNumberCounter,
    bool* isQuizOpened, int* randomQuestion, bool* isAnswered, bool* isEscapeReleased, float* volume, float* soundVolume,
    AllTextures textures, Font font);


void CloseSetting(bool* areSettingsOpen, bool* isEscapeReleased, AllTextures textures);


void BackToMenu(bool* isMenuOpen, bool* openMap, int* questionsNumberCounter, bool* isQuizOpened, int* randomQuestion,
    bool* isAnswered, AllTextures textures, Font font);


void BackToMap(bool* isMenuOpen, bool* openMap, int* countryNumber, int* questionsNumberCounter, bool* isQuizOpened, int* randomQuestion,
    bool* isAnswered, AllTextures textures, Font font);


void SetFPS(AllTextures textures, Font font);


void ChangeMusicVolume(float* musicVolume, AllTextures textures, Font font);


void ChangeSoundVolume(float* soundVolume, AllTextures textures, Font font);