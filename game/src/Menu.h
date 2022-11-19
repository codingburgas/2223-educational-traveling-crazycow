#pragma once
#include "Main.h"

void DrawMenuBackground(MenuS& menu, AllTextures textures);

void StartGame(bool& isMenuOpen, MapS& map, AllTextures textures, Font font);

void CloseGame(bool& Close, AllTextures textures, Font font);

void NewGame(bool& newGame, AllTextures textures, Font font);

void NewGameWarning(bool& newGame, GameS& game, LockedCountries& lockedCountries, AllTextures textures, Font font);

void ResetValues(GameS& game, LockedCountries& lockedCountries);