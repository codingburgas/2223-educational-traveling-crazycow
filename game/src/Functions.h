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

struct Variables {
    struct Booleans {
        bool areSettingsOpen = false;
        bool isGameClosed = false;
        bool isMenuOpen = true;
        bool openMap = false;
        bool countryList = false;
        bool isQuizOpened = false;
        bool isAnswered = true;
        bool isEscapeReleased = false;
    }bools;

    struct LockedCountriesBooleans {
        bool isBulgariaOpen = true;
        bool isSpainOpen = false;
        bool isFranceOpen = false;
        bool isItalyOpen = false;
        bool isGermanyOpen = false;
        bool isGreeceOpen = false;
        bool isTurkeyOpen = false;
        bool isUnitedKingdomOpen = false;
        bool isNorwayOpen = false;
    }countryBools;

    struct Integers {
        int countryNumber = 0;
        int countryHover = 0;
        int mapLocation = 0;
        int BusX = 0;
        int BusY = 590;
        int BGX = 0;
        int money = 150;
        int trueQuestionCounter = 0;
        int questionsNumberCounter = 0;
        int randomQuestion = 0;
    }ints;
};

struct AllTextures {

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

    Texture2D menuCaravanLeft = LoadTexture("../src/assets/Backgrounds/menuCaravan_one.png");
    Texture2D menuCaravanMiddle = LoadTexture("../src/assets/Backgrounds/menuCaravan_two.png");
    Texture2D menuCaravanRight = LoadTexture("../src/assets/Backgrounds/menuCaravan_three.png");

    // Others

    Texture2D settingsIcon = LoadTexture("../src/assets/Others/SettingIcon.png");
    Texture2D closeSettingsIcon = LoadTexture("../src/assets/Others/CloseSettingsIcon.png");
    Texture2D wheatIcon = LoadTexture("../src/assets/Others/WheatIcon.png");
};

// Main Functions ----------------------------------------------------------------------------------------------------------------------
void Menu(bool* isGameClosed, bool* isMenuOpen, bool* openMap, int* BusX, int* BusY,
    int* BGX, int* countryNumber, AllTextures textures, Font font);

void Settings(bool* areSettingsOpen, bool* isMenuOpen, bool* openMap, int* countryNumber, int* questionsNumberCounter,
              bool* isQuizOpened, int* randomQuestion, bool* isAnswered, bool* isEscapeReleased, AllTextures textures, Font font);

void Game(bool* openMap, int* countryNumber, int* countryHover, bool* countryList, int* mapLocation, bool* areSettingsOpen,
          int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isMenuOpen, bool* isQuizOpened,
          bool* isAnswered, AllTextures textures, Font font, Variables :: LockedCountriesBooleans *lockedCountries);


// Settings Functions ------------------------------------------------------------------------------------------------------------------

void OpenSettings(bool* areSettingsOpen, bool* isMenuOpen, bool* openMap, int* countryNumber, int* questionsNumberCounter,
    bool* isQuizOpened, int* randomQuestion, bool* isAnswered, bool* isEscapeReleased, AllTextures textures, Font font);

void CloseSetting(bool* areSettingsOpen, bool* isEscapeReleased, AllTextures textures);

void BackToMenu(bool* isMenuOpen, bool* openMap, int* questionsNumberCounter, bool* isQuizOpened, int* randomQuestion,
    bool* isAnswered, AllTextures textures, Font font);

void BackToMap(bool* isMenuOpen, bool* openMap, int* countryNumber, int* questionsNumberCounter, bool* isQuizOpened, int* randomQuestion,
    bool* isAnswered, AllTextures textures, Font font);

void SetFPS(AllTextures textures, Font font);


// Menu Functions ---------------------------------------------------------------------------------------------------------------------

void DrawMenuBackground(int* BusX, int* Bus, int* BGX, AllTextures textures);

void StartGame(bool* isMenuOpen, bool* openMap, int* countryNumber, AllTextures textures, Font font);

void CloseGame(bool* Close, AllTextures textures, Font font);

// Game Functions -------------------------------------------------------------------------------------------------------------------

// Functions according to the map - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

void MoveMap(int* mapLocation, AllTextures textures);

void OpenTheMap(int* mapLocation, int* countryHover, bool* countryList, bool* areSettingsOpen, AllTextures textures);

void ChooseCountry(int* countryNumber, int* countryHover, bool* areSettingsOpen, AllTextures textures, Font font,
                   Variables::LockedCountriesBooleans* lockedCountries);

void DrawCountry(Font font, const char* name, float x, float y, float lengthX, float lengthY, int countryNum, int* countryNumber, int* countryHover,
    bool* areSettingsOpen, bool* lockedCountry);

void OpenCountries(int* countryNumber, int* countryHover, int* mapLocation, bool* countryList, bool* areSettingsOpen, AllTextures textures, Font font,
                   Variables::LockedCountriesBooleans* lockedCountries);


// Functions according to the countries - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


void OpenCountry(int* countryNumber, int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion,
    bool* isQuizOpened, bool* isAnswered, AllTextures textures, Font font);

void OpenQuiz(const char** questions, const char* answers[10][4], int* tPos, int* money, int* trueQuestionCounter,
    int* questionsNumberCounter, int* randomQuestion, bool* isAnswered, bool* isQuizOpened, AllTextures textures, Font font);

void AnswerPosition(int tPos, const char* question, const char** answers, int* trueQuestionCounter, int* questionsNumberCounter,
                    int* randomQuestion, bool* isAnswered, AllTextures textures, Font font);

void Answer(int tPos, int tPosVal, int x1, int y1, int x2, int y2, const char** answers, int* trueQuestionCounter,
    int* questionsNumberCounter, bool* isAnswered, AllTextures textures, Font font);



// Other Functions ----------------------------------------------------------------------------------------------------------------

bool IsMouseInRange(int x1, int x2, int y1, int y2);

Vector2 VecPos(int x, int y);

void UnloadAllTextures(AllTextures unloadTextures);



// Country Questions Functions -----------------------------------------------------------------------------------------------------

void OpenBulgaria(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
    bool* isAnswered, AllTextures textures, Font font);

void OpenSpain(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
    bool* isAnswered, AllTextures textures, Font font);

void OpenFrance(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
    bool* isAnswered, AllTextures textures, Font font);

void OpenItaly(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
    bool* isAnswered, AllTextures textures, Font font);

void OpenGermany(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
    bool* isAnswered, AllTextures textures, Font font);

void OpenTurkey(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
    bool* isAnswered, AllTextures textures, Font font);

void OpenGreece(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
    bool* isAnswered, AllTextures textures, Font font);

void OpenEngland(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
    bool* isAnswered, AllTextures textures, Font font);

void OpenNorway(int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion, bool* isQuizOpened,
    bool* isAnswered, AllTextures textures, Font font);