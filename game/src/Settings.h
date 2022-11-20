#pragma once
#include "Main.h"

void OpenSettings(SettingsS& settings, FlyingCows& cows, MenuS& menu, MapS& map, GameS& game, AllTextures textures, Font font);


void CloseSetting(SettingsS& settings, AllTextures textures);


void BackToMenu(bool& isMenuOpen, MapS& map, FlyingCows& cows, GameS& game, AllTextures textures, Font font);


void BackToMap(bool& isMenuOpen, MapS& map, FlyingCows& cows, GameS& game, AllTextures textures, Font font);


void SetFPS(AllTextures textures, Font font);


void ChangeMusicVolume(float& musicVolume, AllTextures textures, Font font);


void ChangeSoundVolume(float& soundVolume, AllTextures textures, Font font);