#pragma once
#include "Include.h"

// Creates event after you have not enough money to continue the game. Display background, hand with dart and targets. When all targets are down you earn hay.
void CrazyCow(FlyingCows& cows, GameS& game, MenuS& menu, AllTextures textures, Font font);

// Moves the arm on CrazyCow even
void MoveArmCC(GameS& game);

// Displays flying cows that move in random directions on the map.
void FlyingCow(int cowNum, FlyingCows& cows, GameS& game, AllTextures textures);

// Checks if the cow is hit by the dart
void HitCow(int cowNum, FlyingCows& cows, GameS& game);

// Checks if you don't have enough hay and display a button to start crazy cow event.
void OpenCrazyCow(FlyingCows& cows, GameS& game, MenuS& menu, MapS& map, AllTextures textures, Font font);

// Checks if money are needed to show CrazyCow event
bool NeedMoney(GameS& game, int unlockedCountries);

// Finishes CrazyCow event
void FinishCrazyCow(FlyingCows& cows, GameS& game, MenuS& menu, AllTextures textures, Font font);
