#pragma once
#include "Include.h"

// Quiz -----------------------------------------------------------------------------------------------------------------------------------

void OpenCountry(int& countryNumber, GameS& game, AllTextures textures, Font font);


void OpenQuiz(const char** questions, const char* answers[10][4], int* tPos, int& quizCounter, GameS& game, AllTextures textures, Font font);


void AnswerPosition(int tPos, const char* question, const char** answers, GameS& game, AllTextures textures, Font font);


void Answer(int tPos, int tPosVal, int x1, int y1, const char** answers, GameS& game, AllTextures textures, Font font);


// Game -------------------------------------------------------------------------------------------------------------------------------------

void OpenGame(int& gameCounter, int landmarkPos, Texture2D landmarks[4], Texture2D background, Texture2D armOne, Texture2D armTwo,
			  GameS& game, AllTextures textures, Font font);

void MoveArm(GameS& game);

bool IsMissed(int randomNums[4], int landmarkPos, GameS& game);

bool IsHit(int landmarkPos, GameS& game);
