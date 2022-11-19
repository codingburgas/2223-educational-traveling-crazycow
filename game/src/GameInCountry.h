#pragma once
#include "Main.h"

// Quiz -----------------------------------------------------------------------------------------------------------------------------------

void OpenCountry(int& countryNumber, GameS& game, AllTextures textures, Font font);


void OpenQuiz(const char** questions, const char* answers[10][4], int* tPos, int& quizCounter, GameS& game, AllTextures textures, Font font);


void AnswerPosition(int tPos, const char* question, const char** answers, GameS& game, AllTextures textures, Font font);


void Answer(int tPos, int tPosVal, int x1, int y1, const char** answers, GameS& game, AllTextures textures, Font font);


// Game -------------------------------------------------------------------------------------------------------------------------------------

void OpenGame(GameS& game, AllTextures textures, Font font);

void MoveArm(GameS& game, AllTextures textures, Font font);
