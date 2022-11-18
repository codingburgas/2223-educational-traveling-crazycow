#pragma once
#include "raylib.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <time.h>
#include <algorithm>
#include <vector>

using namespace std;

struct SettingsS
{
    bool areSettingsOpen = false;
    bool isEscapeReleased = false;

    float musicVolume = 0.05;
    float soundVolume = 0.15;
};

struct MenuS
{
    bool isMenuOpen = true;
    bool isGameClosed = false;

    int BusX = 0;
    int BusY = 590;
    int BGX = 0;
};

struct MapS
{
    bool openMap = false;
    bool countryList = false;
    bool isWarningOpen = false;

    int countryNumber = 0;
    int countryHover = 0;
    int mapLocation = 0;
};

struct GameS
{
    bool isQuizOpened = false;
    bool isAnswered = true;
    bool openQuiz = true;
    bool isGameOpened = false;
    bool openGame = false;

    int money = 800;
    int trueQuestionCounter = 0;
    int questionsNumberCounter = 0;
    int randomQuestion = 0;
    int quizCounter = 0;
};

struct LockedCountries
{
    bool isBulgariaOpen = true;
    bool isSpainOpen = false;
    bool isFranceOpen = false;
    bool isItalyOpen = false;
    bool isGermanyOpen = false;
    bool isGreeceOpen = false;
    bool isTurkeyOpen = false;
    bool isUnitedKingdomOpen = false;
    bool isNorwayOpen = false;
};

struct AllTextures 
{
    // Boxes

    Texture2D settingsBox = LoadTexture("../src/assets/Boxes/SettingsBox.png");
    Texture2D woodBox = LoadTexture("../src/assets/Boxes/WoodBox.png");
    Texture2D quizBox = LoadTexture("../src/assets/Boxes/QuizBox.png");
    Texture2D taskBox = LoadTexture("../src/assets/Boxes/TaskBox.png");

    Texture2D startBlock = LoadTexture("../src/assets/Boxes/StartBlock.png");
    Texture2D answerBlock = LoadTexture("../src/assets/Boxes/AnswerBlock.png");

    Texture2D leftArrow = LoadTexture("../src/assets/Boxes/LeftArrow.png");
    Texture2D rightArrow = LoadTexture("../src/assets/Boxes/RightArrow.png");
    

    // Maps

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

    // Backgrounds

    Texture2D background = LoadTexture("../src/assets/Backgrounds/Background.png");

    Texture2D quizBackgroundBulgaria = LoadTexture("../src/assets/Backgrounds/Bulgaria.png");
    Texture2D quizBackgroundFrance = LoadTexture("../src/assets/Backgrounds/France.png");
    Texture2D quizBackgroundItaly = LoadTexture("../src/assets/Backgrounds/Italy.png");
    Texture2D quizBackgroundSpain = LoadTexture("../src/assets/Backgrounds/Spain.png");
    Texture2D quizBackgroundGermany = LoadTexture("../src/assets/Backgrounds/Germany.png");

    Texture2D menuCaravanLeft = LoadTexture("../src/assets/Backgrounds/menuCaravan_one.png");
    Texture2D menuCaravanMiddle = LoadTexture("../src/assets/Backgrounds/menuCaravan_two.png");
    Texture2D menuCaravanRight = LoadTexture("../src/assets/Backgrounds/menuCaravan_three.png");

    // Others

    Texture2D settingsIcon = LoadTexture("../src/assets/Others/SettingIcon.png");
    Texture2D closeSettingsIcon = LoadTexture("../src/assets/Others/CloseSettingsIcon.png");
    Texture2D wheatIcon = LoadTexture("../src/assets/Others/WheatIcon.png");
    Texture2D chain = LoadTexture("../src/assets/Others/chain.png");
    Texture2D gameRight = LoadTexture("../src/assets/Others/gameRight.png");
    Texture2D gameLeft = LoadTexture("../src/assets/Others/gameLeft.png");

    // Sounds and Musics

    Sound clickSound = LoadSound("../src/assets/Sounds/ClickSound.mp3");

    Music menuMusic = LoadMusicStream("../src/assets/Sounds/menuMusic.mp3");
};



// Main Functions ----------------------------------------------------------------------------------------------------------------------

void Menu(SettingsS& settings, MenuS& menu, MapS& map, AllTextures textures, Font font);

void Settings(SettingsS& settings, MenuS& menu, MapS& map, GameS& game, AllTextures textures, Font font);

void Game(SettingsS &settings, MenuS &menu, MapS &map, GameS &game, LockedCountries &lockedCountries, AllTextures textures, Font font);




// Menu Functions ---------------------------------------------------------------------------------------------------------------------

void DrawMenuBackground(MenuS& menu, AllTextures textures);

void StartGame(bool& isMenuOpen, MapS& map, AllTextures textures, Font font);

void CloseGame(bool& Close, AllTextures textures, Font font);





// Other Functions ----------------------------------------------------------------------------------------------------------------

bool IsMouseInRange(int x1, int x2, int y1, int y2);

Vector2 VecPos(int x, int y);

void UnloadAllTextures(AllTextures unloadTextures);