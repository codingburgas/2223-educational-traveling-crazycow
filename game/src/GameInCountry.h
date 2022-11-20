#pragma once
#include "Include.h"

// Quiz -----------------------------------------------------------------------------------------------------------------------------------

// Draws quiz background. Displays questions and answers randomly. Takes you hay to start your attempt.
// After you finish your attempt it gives you hay based on how many right answers you have. After the third attempt closes the quiz.
void OpenCountry(int& countryNumber, GameS& game, AllTextures textures, Font font);

// Sets quiz background and all questions and answers.
void OpenQuiz(const char** questions, const char* answers[10][4], int* tPos, int& quizCounter, GameS& game, AllTextures textures, Font font);

// Checks on which position is the answer
void AnswerPosition(int tPos, const char* question, const char** answers, GameS& game, AllTextures textures, Font font);

// Check if it's answered and if the answer is correct
void Answer(int tPos, int tPosVal, int x1, int y1, const char** answers, GameS& game, AllTextures textures, Font font);


// Game -------------------------------------------------------------------------------------------------------------------------------------


// Draws mini game background. Displays mini game frames randomly. Takes you hay to start your attempt.
// After you finish your attempt it gives you hay if you choose the right frame. After the third attempt closes the mini game.
void OpenGame(int& gameCounter, int landmarkPos, Texture2D landmarks[4], Texture2D background, Texture2D armOne, Texture2D armTwo,
			  GameS& game, AllTextures textures, Font font);

// When mini game is opened displays an arm that holds dart that can move up, down, right and left and when space pressed throw the dart.
void MoveArm(GameS& game);

// Checks if IsHit() function is true or false
bool IsMissed(int randomNums[4], int landmarkPos, GameS& game);

// Check that the arrow is stuck in the correct frame and gives you hay if it is.
bool IsHit(int landmarkPos, GameS& game);
