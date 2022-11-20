#pragma once
#include "Include.h"

// Creates game menu background animation
void DrawMenuBackground(MenuS& menu, AllTextures textures);

// Creates a button that takes the player to the game.
void StartGame(bool& isMenuOpen, MapS& map, AllTextures textures, Font font);

// Creates a button that takes the player out of the game
void CloseGame(bool& Close, AllTextures textures, Font font);

// Creates a button that reset the game. The game start from the beginning
void NewGame(bool& newGame, AllTextures textures, Font font);

void NewGameWarning(bool& newGame, GameS& game, FlyingCows& cows, LockedCountries& lockedCountries, AllTextures textures, Font font);

// Player progress is reset. All values are returned to default.
void ResetValues(GameS& game, FlyingCows& cows, LockedCountries& lockedCountries);