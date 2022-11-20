#pragma once
#include "Main.h"

void MoveMap(int& mapLocation, AllTextures textures);


void OpenTheMap(bool& areSettingsOpen, MapS& map, AllTextures textures);


void ChooseCountry(bool& areSettingsOpen, int& money, MapS& map,AllTextures textures, Font font, LockedCountries& lockedCountries);


void DrawCountry(const char* name, int x, int y, int lengthX, int lenghtY, int countryNum, MapS& map,
    bool& areSettingsOpen, int& money, bool& lockedCountry, AllTextures textures, Font font);


void OpenCountries(bool& areSettingsOpen, int& money, MapS& map, AllTextures textures, Font font, LockedCountries& lockedCountries);


void OpenWarning(bool* saveLockedCountry, int& money, MapS& map, AllTextures textures, Font font);