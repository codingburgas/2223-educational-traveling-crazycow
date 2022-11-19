#include "Main.h"

bool IsMouseInRange(int x1, int x2, int y1, int y2)
{
    if (GetMouseX() >= x1 && GetMouseX() <= x2 && GetMouseY() >= y1 && GetMouseY() <= y2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Vector2 VecPos(int x, int y)
{
    Vector2 pos = {0,0};
    pos.x = x;
    pos.y = y;
    return pos;
}

void SaveData(ofstream& saveData, GameS& game, LockedCountries& lockedCountries)
{
    saveData.open("../src/assets/SaveData.txt");

    if (saveData.is_open())
    {
        saveData << game.money << endl;
        saveData << game.quizCounter[0] << endl;
        saveData << game.quizCounter[1] << endl;
        saveData << game.quizCounter[2] << endl;
        saveData << game.quizCounter[3] << endl;
        saveData << game.quizCounter[4] << endl;
        saveData << game.quizCounter[5] << endl;
        saveData << game.quizCounter[6] << endl;
        saveData << game.quizCounter[7] << endl;
        saveData << game.quizCounter[8] << endl;

        saveData << lockedCountries.isSpainOpen << endl;
        saveData << lockedCountries.isFranceOpen << endl;
        saveData << lockedCountries.isItalyOpen << endl;
        saveData << lockedCountries.isGermanyOpen << endl;
        saveData << lockedCountries.isTurkeyOpen << endl;
        saveData << lockedCountries.isGreeceOpen << endl;
        saveData << lockedCountries.isUnitedKingdomOpen << endl;
        saveData << lockedCountries.isNorwayOpen << endl;

        saveData.close();
    }
}

void GetData(ifstream& getData, GameS& game, LockedCountries& lockedCountries)
{
    getData.open("../src/assets/SaveData.txt");

    if (getData.is_open())
    {
        getData >> game.money;
        getData >> game.quizCounter[0];
        getData >> game.quizCounter[1];
        getData >> game.quizCounter[2];
        getData >> game.quizCounter[3];
        getData >> game.quizCounter[4];
        getData >> game.quizCounter[5];
        getData >> game.quizCounter[6];
        getData >> game.quizCounter[7];
        getData >> game.quizCounter[8];

        getData >> lockedCountries.isSpainOpen;
        getData >> lockedCountries.isFranceOpen;
        getData >> lockedCountries.isItalyOpen;
        getData >> lockedCountries.isGermanyOpen;
        getData >> lockedCountries.isTurkeyOpen;
        getData >> lockedCountries.isGreeceOpen;
        getData >> lockedCountries.isUnitedKingdomOpen;
        getData >> lockedCountries.isNorwayOpen;

        getData.close();
    }
}

void UnloadAllTextures(AllTextures unloadTextures)
{
    // Unload Boxes

    UnloadTexture(unloadTextures.settingsBox);
    UnloadTexture(unloadTextures.woodBox);
    UnloadTexture(unloadTextures.quizBox);
    UnloadTexture(unloadTextures.taskBox);
    
    UnloadTexture(unloadTextures.startBlock);
    UnloadTexture(unloadTextures.answerBlock);
    
    UnloadTexture(unloadTextures.leftArrow);
    UnloadTexture(unloadTextures.rightArrow);
    
    // Unload Maps

    UnloadTexture(unloadTextures.europeMap);
    UnloadTexture(unloadTextures.europeBulgaria);
    UnloadTexture(unloadTextures.europeSpain);
    UnloadTexture(unloadTextures.europeFrance);
    UnloadTexture(unloadTextures.europeItaly);
    UnloadTexture(unloadTextures.europeGermany);
    UnloadTexture(unloadTextures.europeTurkey);
    UnloadTexture(unloadTextures.europeGreece);
    UnloadTexture(unloadTextures.europeEngland);
    UnloadTexture(unloadTextures.europeNorway);

    // Unload Backgrounds

    UnloadTexture(unloadTextures.background);

    UnloadTexture(unloadTextures.quizBackgroundBulgaria);
    UnloadTexture(unloadTextures.quizBackgroundFrance);
    UnloadTexture(unloadTextures.quizBackgroundItaly);
    UnloadTexture(unloadTextures.quizBackgroundSpain);
    UnloadTexture(unloadTextures.quizBackgroundGermany);
    UnloadTexture(unloadTextures.quizBackgroundGreece);

    UnloadTexture(unloadTextures.menuCaravanLeft);
    UnloadTexture(unloadTextures.menuCaravanMiddle);
    UnloadTexture(unloadTextures.menuCaravanRight);

    // Unload Others

    UnloadTexture(unloadTextures.settingsIcon);
    UnloadTexture(unloadTextures.closeSettingsIcon);
    UnloadTexture(unloadTextures.wheatIcon);
    UnloadTexture(unloadTextures.chain);
    UnloadTexture(unloadTextures.gameRight);
    UnloadTexture(unloadTextures.gameLeft);
    UnloadTexture(unloadTextures.armStageOne);
    UnloadTexture(unloadTextures.armStageTwo);
    UnloadTexture(unloadTextures.dart);
}