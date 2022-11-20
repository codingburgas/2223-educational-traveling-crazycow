#pragma once
#include "Include.h"

void CrazyCow(FlyingCows& cows, GameS& game, MenuS& menu, AllTextures textures, Font font);

void MoveArmCC(GameS& game);

void FlyingCow(int cowNum, FlyingCows& cows, GameS& game, AllTextures textures);

void HitCow(int cowNum, FlyingCows& cows, GameS& game);

void OpenCrazyCow(FlyingCows& cows, GameS& game, MenuS& menu, MapS& map, AllTextures textures, Font font);

bool NeedMoney(GameS& game, int unlockedCountries);

void FinishCrazyCow(FlyingCows& cows, GameS& game, MenuS& menu, AllTextures textures, Font font);
