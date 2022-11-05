#pragma once
#include "raylib.h"
#include <iostream>
#include <vector>

using namespace std;

struct Variables {
    struct Booleans {
        bool areSettingsOpen = false;
        bool isGameClosed = false;
        bool isMenuOpen = true;
        bool chooseCountry = false;
    }bools;

    struct Integrears {
        int countryNumber = 0;
        int BusX = 0;
        int BusY = 600;
        int BGX = 0;
    }ints;
};

struct AllTextures {
    Texture2D settingsBox = LoadTexture("../src/assets/SettingsBox.png");
    Texture2D closeSettingsIcon = LoadTexture("../src/assets/CloseSettingsIcon.png");
    Texture2D taskBox = LoadTexture("../src/assets/TaskBox.png");
    Texture2D settingsIcon = LoadTexture("../src/assets/SettingIcon.png");
    Texture2D busIcon = LoadTexture("../src/assets/BusIcon.png");
    Texture2D startBlock = LoadTexture("../src/assets/StartBlock.png");
    Texture2D europeMap = LoadTexture("../src/assets/EuropeMap.png");
    Texture2D background = LoadTexture("../src/assets/Background.gif");
};

struct Animation {
    int frames = 10;
    //Image image = LoadImageAnim("../src/assets/Background.gif", &frames);
    //Texture2D texture= LoadTextureFromImage(image);
};

void OpenSettings(bool* areSettingsOpen, bool* isMenuOpen, bool* chooseCountry, AllTextures textures);
void CloseSetting(bool* areSettingsOpen, AllTextures textures);

void BackToMenu(bool* isMenuOpen, bool* chooseCountry, AllTextures textures);


void Menu(bool* Close, bool* areSettingsOpen, bool* isMenuOpen, int* countryNumber, bool* chooseCountry, int* BusX, int* BusY,
    int* BGX, AllTextures textures, Animation animation);

void CloseGame(bool* Close, AllTextures textures);
void StartGame(bool* isMenuOpen, bool* chooseCountry, AllTextures textures);

bool IsMouseInRange(int x1, int x2, int y1, int y2);


void ChooseCountry(int* countryNumber, AllTextures textures);

void unloadAllTextures(AllTextures unloadTextures);
//void unloadAllAnimations(Animation animation);

void DrawMenuBackground(int* BusX, int* Bus, int* BGX, AllTextures textures, Animation animation);

//void DrawAnimation(Animation animation, int x, int y, Color color);