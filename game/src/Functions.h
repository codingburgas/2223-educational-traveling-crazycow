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
        bool openMap = false;
        bool countryList = false;
    }bools;

    struct Integers {
        int countryNumber = 0;
        int countryHover = 0;
        int mapLocation = 0;
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
    Texture2D background = LoadTexture("../src/assets/Background.png");
    Texture2D leftArrow = LoadTexture("../src/assets/LeftArrow.png");
    Texture2D rightArrow = LoadTexture("../src/assets/RightArrow.png");
    Texture2D woodBox = LoadTexture("../src/assets/WoodBox.png");

    Texture2D europeMap = LoadTexture("../src/assets/Maps/EuropeMap.png");
    Texture2D europeBulgaria = LoadTexture("../src/assets/Maps/EuropeBulgaria.png");
    Texture2D europeSpain = LoadTexture("../src/assets/Maps/EuropeSpain.png");
    Texture2D europeFrance = LoadTexture("../src/assets/Maps/EuropeFrance.png");
    Texture2D europeItaly = LoadTexture("../src/assets/Maps/EuropeItaly.png");
    Texture2D europeGermany = LoadTexture("../src/assets/Maps/EuropeGermany.png");
    Texture2D europeTurkey = LoadTexture("../src/assets/Maps/EuropeTurkey.png");
    Texture2D europeGreece = LoadTexture("../src/assets/Maps/EuropeGreece.png");
    Texture2D europeEngland = LoadTexture("../src/assets/Maps/EuropeEngland.png");
    Texture2D europeNorway = LoadTexture("../src/assets/Maps/EuropeNorway.png");
};

void OpenSettings(bool* areSettingsOpen, bool* isMenuOpen, bool* chooseCountry, AllTextures textures, Font font);
void CloseSetting(bool* areSettingsOpen, AllTextures textures);

void BackToMenu(bool* isMenuOpen, bool* chooseCountry, AllTextures textures, Font font);




void Menu(bool* isGameClosed, bool* isMenuOpen, bool* openMap, int* BusX, int* BusY,
    int* BGX, AllTextures textures, Font font);

void Settings(bool* areSettingsOpen, bool* isMenuOpen, bool* openMap, AllTextures textures, Font font);

void Game(bool* openMap, int* countryNumber, int* countryHover, bool* countryList, int* mapLocation, AllTextures textures, Font font);




void StartGame(bool* isMenuOpen, bool* openMap, AllTextures textures, Font font);
void CloseGame(bool* Close, AllTextures textures, Font font);

bool IsMouseInRange(int x1, int x2, int y1, int y2);


void OpenTheMap(int* mapLocation, int* countryHover, bool* countryList, AllTextures textures);

void OpenCountries(int* countryNumber, int* countryHover, int* mapLocation, bool* countryList, AllTextures textures, Font font);

void UnloadAllTextures(AllTextures unloadTextures);

void DrawMenuBackground(int* BusX, int* Bus, int* BGX, AllTextures textures);

void MoveMap(int* mapLocation, AllTextures textures);

void ChooseCountry(int* countryNumber, int* countryHover, AllTextures textures, Font font);

void DrawCountry(Font font, const char* name, int x, int y, int lengthX, int lengthY, int countryNum, int* countryNumber, int* countryHover);