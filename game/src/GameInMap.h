#pragma once
#include "Include.h"

// Makes the map movable when the list of countries is opened.
void MoveMap(int& mapLocation, AllTextures textures);

// Opens the map when the player wants to go there
void OpenTheMap(bool& areSettingsOpen, MapS& map, AllTextures textures);

// Creates expandable list of countries and hover the country on the map if your mouse is over its name.
void ChooseCountry(bool& areSettingsOpen, int& money, MapS& map,AllTextures textures, Font font, LockedCountries& lockedCountries);

// Draw a country on a specific position 
void DrawCountry(const char* name, float x, float y, float lengthX, float lenghtY, int countryNum, MapS& map,
    bool& areSettingsOpen, int& money, bool& lockedCountry, AllTextures textures, Font font);

// Opens the list of countries
void OpenCountries(bool& areSettingsOpen, int& money, MapS& map, AllTextures textures, Font font, LockedCountries& lockedCountries);

// Opens a warning if the player wants to unlock a country
void OpenWarning(bool* saveLockedCountry, int& money, MapS& map, AllTextures textures, Font font);