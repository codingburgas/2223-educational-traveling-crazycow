#pragma once
#include "Main.h"

void MoveMap(int* mapLocation, AllTextures textures);


void OpenTheMap(int* mapLocation, int* countryHover, bool* countryList, bool* areSettingsOpen, AllTextures textures);


void ChooseCountry(int* countryNumber, int* countryHover, bool* areSettingsOpen, int* money, bool* isWarningOpen, AllTextures textures, Font font,
    Variables::LockedCountriesBooleans* lockedCountries);


void DrawCountry(Font font, const char* name, float x, float y, float lengthX, float lenghtY, int countryNum, int* countryNumber, int* countryHover,
    bool* areSettingsOpen, bool* lockedCountry, int* money, bool* isWarningOpen, AllTextures textures);


void OpenCountries(int* countryNumber, int* countryHover, int* mapLocation, bool* countryList, bool* areSettingsOpen, int* money,
    bool* isWarningOpen, AllTextures textures, Font font, Variables::LockedCountriesBooleans* lockedCountries);


void OpenWarning(bool* saveLockedCountry, bool* isWarningOpen, int* money, AllTextures textures, Font font);