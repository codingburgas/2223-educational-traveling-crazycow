#pragma once
#include "raylib.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <time.h>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

const int screenWidth = 1920;
const int screenHeight = 1000;

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
    bool newGame = false;

    int BusX = 0;
    int BusY = 590;
    int BGX = 0;
};

struct MapS
{
    bool openMap = false;
    bool countryList = false;
    bool countryWarning = false;

    int countryNumber = 0;
    int countryHover = 0;
    int mapLocation = 0;
};

struct GameS
{
    bool isQuizOpened = false;
    bool openQuiz = true;
    bool isAnswered = true;
    bool isGameOpened = false;
    bool openGame = false;
    bool isArrowPressed = false;
    bool gameWarning = false;
    bool gameWin = false;
    bool gameLoose = false;

    int money = 600;
    int trueQuestionCounter = 0;
    int questionsNumberCounter = 0;
    int randomQuestion = 0;

    int armX = 500;
    int armY = 600;

    int dartX = 500 + 20;
    int dartY = 600 - 10;

    bool flyingDart = false;

    int quizCounter[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    int gameCounter[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
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
    Texture2D quizBackgroundGreece = LoadTexture("../src/assets/Backgrounds/Greece.png");
    Texture2D quizBackgroundTurkey = LoadTexture("../src/assets/Backgrounds/Turkey.png");
    Texture2D gameBackground = LoadTexture("../src/assets/Backgrounds/gameBackground.png");

    Texture2D menuCaravanLeft = LoadTexture("../src/assets/Backgrounds/menuCaravan_one.png");
    Texture2D menuCaravanMiddle = LoadTexture("../src/assets/Backgrounds/menuCaravan_two.png");
    Texture2D menuCaravanRight = LoadTexture("../src/assets/Backgrounds/menuCaravan_three.png");

    // Landmarks

    Texture2D BulgariaLandmark = LoadTexture("../src/assets/Landmarks/BulgariaLandmark.png");
    Texture2D FranceLandmark = LoadTexture("../src/assets/Landmarks/FranceLandmark.png");
    Texture2D GermanyLandmark = LoadTexture("../src/assets/Landmarks/GermanyLandmark.png");
    Texture2D GreeceLandmark = LoadTexture("../src/assets/Landmarks/GreeceLandmark.png");
    Texture2D ItalyLandmark = LoadTexture("../src/assets/Landmarks/ItalyLandmark.png");
    Texture2D SpainLandmark = LoadTexture("../src/assets/Landmarks/SpainLandmark.png");
    Texture2D TurkeyLandmark = LoadTexture("../src/assets/Landmarks/TurkeyLandmark.png");

    // Others

    Texture2D settingsIcon = LoadTexture("../src/assets/Others/SettingIcon.png");
    Texture2D closeSettingsIcon = LoadTexture("../src/assets/Others/CloseSettingsIcon.png");
    Texture2D wheatIcon = LoadTexture("../src/assets/Others/WheatIcon.png");
    Texture2D chain = LoadTexture("../src/assets/Others/chain.png");
    Texture2D gameRight = LoadTexture("../src/assets/Others/gameRight.png");
    Texture2D gameLeft = LoadTexture("../src/assets/Others/gameLeft.png");
    Texture2D armStageOne = LoadTexture("../src/assets/Others/armStageOne.png");
    Texture2D armStageTwo = LoadTexture("../src/assets/Others/armStageTwo.png");
    Texture2D dart = LoadTexture("../src/assets/Others/dart.png");

    // Sounds and Musics

    Sound clickSound = LoadSound("../src/assets/Sounds/ClickSound.mp3");

    Music menuMusic = LoadMusicStream("../src/assets/Sounds/menuMusic.mp3");
};



// Main Functions ----------------------------------------------------------------------------------------------------------------------

void Menu(MenuS& menu, MapS& map, GameS& game, LockedCountries& lockedCountries, AllTextures textures, Font font);

void Settings(SettingsS& settings, MenuS& menu, MapS& map, GameS& game, AllTextures textures, Font font);

void Game(SettingsS &settings, MenuS &menu, MapS &map, GameS &game, LockedCountries &lockedCountries, AllTextures textures, Font font);


// Other Functions ----------------------------------------------------------------------------------------------------------------

bool IsMouseInRange(int x1, int x2, int y1, int y2);

Vector2 VecPos(int x, int y);

void UnloadAllTextures(AllTextures unloadTextures);

void SaveData(ofstream& saveData, GameS& game, LockedCountries& lockedCountries);

void GetData(ifstream& getData, GameS& game, LockedCountries& lockedCountries);