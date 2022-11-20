#pragma once
#include "Include.h"

// Creates a button that opens the settings menu.
void OpenSettings(SettingsS& settings, FlyingCows& cows, MenuS& menu, MapS& map, GameS& game, AllTextures textures, Font font);

// Creates a button that closes the settings menu.
void CloseSetting(SettingsS& settings, AllTextures textures);

// Creates a button that takes the player to the game menu. 
void BackToMenu(bool& isMenuOpen, MapS& map, FlyingCows& cows, GameS& game, AllTextures textures, Font font);

// Creates a button that takes the player to the game map. 
void BackToMap(bool& isMenuOpen, MapS& map, FlyingCows& cows, GameS& game, AllTextures textures, Font font);

// Creates a box that allows the player to change the FPS
void SetFPS(AllTextures textures, Font font);

// Creates a box that allows the player to change the FPS the music volume.
void ChangeMusicVolume(float& musicVolume, AllTextures textures, Font font);

// Creates a box that allows the player to change the FPS the sound volume.
void ChangeSoundVolume(float& soundVolume, AllTextures textures, Font font);