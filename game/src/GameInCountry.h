#pragma once
#include "Main.h"

// Quiz -----------------------------------------------------------------------------------------------------------------------------------

void OpenCountry(int* countryNumber, int* money, int* trueQuestionCounter, int* questionsNumberCounter, int* randomQuestion,
    bool* isQuizOpened, bool* isAnswered, bool* openQuiz, bool* openGame, bool* isGameOpened, AllTextures textures, Font font);


void OpenQuiz(const char** questions, const char* answers[10][4], int* tPos, int* money, int* trueQuestionCounter,
    int* questionsNumberCounter, int* randomQuestion, bool* isAnswered, bool* isQuizOpened, AllTextures textures, Font font);


void AnswerPosition(int tPos, const char* question, const char** answers, int* trueQuestionCounter, int* questionsNumberCounter,
    int* randomQuestion, bool* isAnswered, AllTextures textures, Font font);


void Answer(int tPos, int tPosVal, int x1, int y1, int x2, int y2, const char** answers, int* trueQuestionCounter,
    int* questionsNumberCounter, bool* isAnswered, AllTextures textures, Font font);


// Game -------------------------------------------------------------------------------------------------------------------------------------

void OpenGame(bool* isGameOpened, int* money, AllTextures textures, Font font);
