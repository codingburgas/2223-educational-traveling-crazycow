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

// set the height and width of the screen
const int screenWidth = 1920;
const int screenHeight = 1000;

// define structure for settigns
struct SettingsS
{
    bool areSettingsOpen = false;
    bool isEscapeReleased = false;

    float musicVolume = (float)0.05;
    float soundVolume = (float)0.15;

    int pages = 1;
};

// define structure for the menu
struct MenuS
{
    bool isMenuOpen = true;
    bool isGameClosed = false;
    bool newGame = false;

    int BusX = 0;
    int BusY = 590;
    int BGX = 0;
};

// define structure for the map
struct MapS
{
    bool openMap = false;
    bool countryList = false;
    bool countryWarning = false;
    bool notEnoughMoney = false;

    int countryNumber = 0;
    int countryHover = 0;
    int mapLocation = 0;

    int unlockedCountries = 1;
};

// define structure for game
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

    int money = 150;
    int trueQuestionCounter = 0;
    int questionsNumberCounter = 0;
    int randomQuestion = 0;

    int armX = 600;
    int armY = 700;

    int dartX = 900;
    int dartY = 700;

    bool flyingDart = false;

    int quizCounter[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    int gameCounter[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
};

// define structure for the locked countries
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

// define structure about CrazyCow event
struct FlyingCows
{
    int cowsX[10] = {
        1 + (rand() % 1900),
        1 + (rand() % 1900),
        1 + (rand() % 1900),
        1 + (rand() % 1900),
        1 + (rand() % 1900),
        1 + (rand() % 1900),
        1 + (rand() % 1900),
        1 + (rand() % 1900),
        1 + (rand() % 1900),
        1 + (rand() % 1900)
    };

    int cowsY[10] = {
        1 + (rand() % 500),
        1 + (rand() % 500),
        1 + (rand() % 500),
        1 + (rand() % 500),
        1 + (rand() % 500),
        1 + (rand() % 500),
        1 + (rand() % 500),
        1 + (rand() % 500),
        1 + (rand() % 500),
        1 + (rand() % 500)

    };

    int randomNums[10] = {
        1 + (rand() % 8),
        1 + (rand() % 8),
        1 + (rand() % 8),
        1 + (rand() % 8),
        1 + (rand() % 8),
        1 + (rand() % 8),
        1 + (rand() % 8),
        1 + (rand() % 8),
        1 + (rand() % 8),
        1 + (rand() % 8)
    };

    int cowsCounters[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    int downCowsCounter = 0;

    int dartsLeft = 15;

    int finishCCDelay = 0;

    bool downCows[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    bool cowDir[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    
    bool isCCOpen = false;

    bool isCCOver = false;

    bool CCWarning = false;
};


// define structure for loading all the textures used
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

    //Quiz

    Texture2D quizBackgroundBulgaria = LoadTexture("../src/assets/Backgrounds/Bulgaria.png");
    Texture2D quizBackgroundFrance = LoadTexture("../src/assets/Backgrounds/France.png");
    Texture2D quizBackgroundItaly = LoadTexture("../src/assets/Backgrounds/Italy.png");
    Texture2D quizBackgroundSpain = LoadTexture("../src/assets/Backgrounds/Spain.png");
    Texture2D quizBackgroundGermany = LoadTexture("../src/assets/Backgrounds/Germany.png");
    Texture2D quizBackgroundGreece = LoadTexture("../src/assets/Backgrounds/Greece.png");
    Texture2D quizBackgroundTurkey = LoadTexture("../src/assets/Backgrounds/Turkey.png");
    Texture2D quizBackgroundNorway = LoadTexture("../src/assets/Backgrounds/Norway.png");
    Texture2D quizBackgroundEngland = LoadTexture("../src/assets/Backgrounds/England.png");


    //Game

    Texture2D gameBackgroundBulgaria = LoadTexture("../src/assets/Backgrounds/BulgariaGame.png");
    Texture2D gameBackgroundFrance = LoadTexture("../src/assets/Backgrounds/FranceGame.png");
    Texture2D gameBackgroundItaly = LoadTexture("../src/assets/Backgrounds/ItalyGame.png");
    Texture2D gameBackgroundSpain = LoadTexture("../src/assets/Backgrounds/SpainGame.png");
    Texture2D gameBackgroundGermany = LoadTexture("../src/assets/Backgrounds/GermanyGame.png");
    Texture2D gameBackgroundGreece = LoadTexture("../src/assets/Backgrounds/GreeceGame.png");
    Texture2D gameBackgroundTurkey = LoadTexture("../src/assets/Backgrounds/TurkeyGame.png");
    Texture2D gameBackgroundNorway = LoadTexture("../src/assets/Backgrounds/NorwayGame.png");
    Texture2D gameBackgroundEngland = LoadTexture("../src/assets/Backgrounds/EnglandGame.png");


    Texture2D menuCaravanLeft = LoadTexture("../src/assets/Backgrounds/menuCaravan_one.png");
    Texture2D menuCaravanMiddle = LoadTexture("../src/assets/Backgrounds/menuCaravan_two.png");
    Texture2D menuCaravanRight = LoadTexture("../src/assets/Backgrounds/menuCaravan_three.png");

    Texture2D crazyCowBG = LoadTexture("../src/assets/Backgrounds/CrazyCowBG.png");

    // Landmarks

    Texture2D BulgariaLandmark = LoadTexture("../src/assets/Landmarks/BulgariaLandmark.png");
    Texture2D FranceLandmark = LoadTexture("../src/assets/Landmarks/FranceLandmark.png");
    Texture2D GermanyLandmark = LoadTexture("../src/assets/Landmarks/GermanyLandmark.png");
    Texture2D GreeceLandmark = LoadTexture("../src/assets/Landmarks/GreeceLandmark.png");
    Texture2D ItalyLandmark = LoadTexture("../src/assets/Landmarks/ItalyLandmark.png");
    Texture2D SpainLandmark = LoadTexture("../src/assets/Landmarks/SpainLandmark.png");
    Texture2D TurkeyLandmark = LoadTexture("../src/assets/Landmarks/TurkeyLandmark.png");
    Texture2D NorwayLandmark = LoadTexture("../src/assets/Landmarks/NorwayLandmark.png");
    Texture2D EnglandLandmark = LoadTexture("../src/assets/Landmarks/UnitedKingdomLandmark.png");

    // Others

    Texture2D settingsIcon = LoadTexture("../src/assets/Others/SettingIcon.png");
    Texture2D closeSettingsIcon = LoadTexture("../src/assets/Others/CloseSettingsIcon.png");
    Texture2D wheatIcon = LoadTexture("../src/assets/Others/WheatIcon.png");
    Texture2D chain = LoadTexture("../src/assets/Others/chain.png");
    Texture2D gameRight = LoadTexture("../src/assets/Others/gameRight.png");
    Texture2D gameLeft = LoadTexture("../src/assets/Others/gameLeft.png");
    Texture2D armStageOne = LoadTexture("../src/assets/Others/armStageOne.png");
    Texture2D armStageTwo = LoadTexture("../src/assets/Others/armStageTwo.png");
    Texture2D norwayArmS2 = LoadTexture("../src/assets/Others/NorwayArmS2.png");
    Texture2D norwayArmS1 = LoadTexture("../src/assets/Others/NorwayArmS1.png");
    Texture2D dart = LoadTexture("../src/assets/Others/dart.png");
    Texture2D miniDart = LoadTexture("../src/assets/Others/MiniDart.png");
    Texture2D flyingCowRight = LoadTexture("../src/assets/Others/FlyingCowRight.png");
    Texture2D flyingCowLeft = LoadTexture("../src/assets/Others/FlyingCowLeft.png");

    Texture2D fallingCowRight = LoadTexture("../src/assets/Others/FallingCowRight.png");
    Texture2D fallingCowLeft = LoadTexture("../src/assets/Others/FallingCowLeft.png");

    Texture2D fallenCowRight = LoadTexture("../src/assets/Others/FallenCowRight.png");
    Texture2D fallenCowLeft = LoadTexture("../src/assets/Others/FallenCowLeft.png");

    // Sounds and Musics

    Sound clickSound = LoadSound("../src/assets/Sounds/ClickSound.mp3");

    Music menuMusic = LoadMusicStream("../src/assets/Sounds/menuMusic.mp3");
};



// Main Functions ----------------------------------------------------------------------------------------------------------------------

// Menu main function. Creats game menu. Calls all menu functions
void Menu(FlyingCows& cows, MenuS& menu, MapS& map, GameS& game, LockedCountries& lockedCountries, AllTextures textures, Font font);

// Settings main function. Creats game settings. Calls all settings functions.
void Settings(SettingsS& settings, FlyingCows& cows, MenuS& menu, MapS& map, GameS& game, AllTextures textures, Font font);

// Game main function. Calls all game functions.
void Game(SettingsS &settings, MenuS &menu, MapS &map, GameS &game, LockedCountries &lockedCountries, AllTextures textures, Font font);


// Other Functions ----------------------------------------------------------------------------------------------------------------

// checks ig the mouse is in a specific range
bool IsMouseInRange(int x1, int x2, int y1, int y2);

// making a vector2s type structure variable for setting a position
Vector2 VecPos(float x, float y);

// Unloads all the textures used
void UnloadAllTextures(AllTextures unloadTextures);

// Saves game progress after closing the game and continue the game after you run it again.
void SaveData(ofstream& saveData, FlyingCows& cows, GameS& game, LockedCountries& lockedCountries);

// Get the data saved before for future uses
void GetData(ifstream& getData, FlyingCows& cows, GameS& game, LockedCountries& lockedCountries);