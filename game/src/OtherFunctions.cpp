#include "Include.h"

// Check mouse collision

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

Vector2 VecPos(float x, float y)
{
    Vector2 pos = {0,0};
    pos.x = x;
    pos.y = y;
    return pos;
}

//Saves game progress after closing the game and continue the game after you run it again.

void SaveData(ofstream& saveData, FlyingCows& cows, MapS& map, GameS& game, LockedCountries& lockedCountries)
{
    saveData.open("../src/assets/SaveData.txt");

    if (saveData.is_open())
    {
        saveData << game.money << endl;

        for (int i = 0; i < 9; i++)
        {
            saveData << game.quizCounter[i] << endl;
        }

        for (int i = 0; i < 9; i++)
        {
            saveData << game.gameCounter[i] << endl;
        }

        saveData << lockedCountries.isSpainOpen << endl;
        saveData << lockedCountries.isFranceOpen << endl;
        saveData << lockedCountries.isItalyOpen << endl;
        saveData << lockedCountries.isGermanyOpen << endl;
        saveData << lockedCountries.isTurkeyOpen << endl;
        saveData << lockedCountries.isGreeceOpen << endl;
        saveData << lockedCountries.isUnitedKingdomOpen << endl;
        saveData << lockedCountries.isNorwayOpen << endl;

        saveData << cows.isCCOver << endl;

        saveData << game.isGameOver << endl;

        saveData << game.finishGame << endl;

        saveData << map.unlockedCountries << endl;

        saveData.close();
    }
}

// Gets player progress

void GetData(ifstream& getData, FlyingCows& cows, MapS& map, GameS& game, LockedCountries& lockedCountries)
{
    getData.open("../src/assets/SaveData.txt");

    if (getData.is_open())
    {
        getData >> game.money;

        for (int i = 0; i < 9; i++)
        {
            getData >> game.quizCounter[i];
        }

        for (int i = 0; i < 9; i++)
        {
            getData >> game.gameCounter[i];
        }

        getData >> lockedCountries.isSpainOpen;
        getData >> lockedCountries.isFranceOpen;
        getData >> lockedCountries.isItalyOpen;
        getData >> lockedCountries.isGermanyOpen;
        getData >> lockedCountries.isTurkeyOpen;
        getData >> lockedCountries.isGreeceOpen;
        getData >> lockedCountries.isUnitedKingdomOpen;
        getData >> lockedCountries.isNorwayOpen;

        getData >> cows.isCCOver;

        getData >> game.isGameOver;

        getData >> game.finishGame;

        getData >> map.unlockedCountries;

        getData.close();
    }
}

void FinishTheGame(MapS& map, MenuS& menu, GameS& game, AllTextures textures, Font font)
{
    if (map.unlockedCountries == 9 && !game.finishGame)
    {
        if (!map.isOkPressed)
        {
            map.openMap = false;
            menu.isMenuOpen = false;
            DrawTexture(textures.crazyCowBG, 0, 0, WHITE);

            DrawTexture(textures.quizBox, 0, 0, WHITE);
            DrawTextEx(font, "Congratulations!", VecPos(510, 284), 120, 8, BLACK);
            DrawTextEx(font, "You unlocked all ", VecPos(650, 400), 70, 8, BLACK);
            DrawTextEx(font, "countries! ", VecPos(780, 470), 70, 8, BLACK);

            DrawTexture(textures.answerBlock, 800, 560, WHITE);
            DrawTextEx(font, "Ok", VecPos(800 + 100, 560 + 30), 60, 6, BLACK);
            if (IsMouseInRange(800, 800 + 300, 560, 560 + 120))
            {
                DrawTextEx(font, "Ok", VecPos(800 + 102, 560 + 26), 60, 6, BLACK);
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    PlaySoundMulti(textures.clickSound);
                    menu.isMenuOpen = true;
                    game.finishGame = true;
                }
            }
        }
        else
        {
            map.isOkPressed = false;
        }
        
    }
}

//Unload all textures

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

    //Quiz

    UnloadTexture(unloadTextures.quizBackgroundBulgaria);
    UnloadTexture(unloadTextures.quizBackgroundFrance);
    UnloadTexture(unloadTextures.quizBackgroundItaly);
    UnloadTexture(unloadTextures.quizBackgroundSpain);
    UnloadTexture(unloadTextures.quizBackgroundGermany);
    UnloadTexture(unloadTextures.quizBackgroundGreece);
    UnloadTexture(unloadTextures.quizBackgroundTurkey);
    UnloadTexture(unloadTextures.quizBackgroundNorway);
    UnloadTexture(unloadTextures.quizBackgroundEngland);
    
    //Game

    UnloadTexture(unloadTextures.gameBackgroundBulgaria);
    UnloadTexture(unloadTextures.gameBackgroundFrance);
    UnloadTexture(unloadTextures.gameBackgroundItaly);
    UnloadTexture(unloadTextures.gameBackgroundSpain);
    UnloadTexture(unloadTextures.gameBackgroundGermany);
    UnloadTexture(unloadTextures.gameBackgroundGreece);
    UnloadTexture(unloadTextures.gameBackgroundTurkey);
    UnloadTexture(unloadTextures.gameBackgroundNorway);
    UnloadTexture(unloadTextures.gameBackgroundEngland);

    UnloadTexture(unloadTextures.menuCaravanLeft);
    UnloadTexture(unloadTextures.menuCaravanMiddle);
    UnloadTexture(unloadTextures.menuCaravanRight);

    UnloadTexture(unloadTextures.crazyCowBG);

    // Unload Landmarks

    UnloadTexture(unloadTextures.BulgariaLandmark);
    UnloadTexture(unloadTextures.FranceLandmark);
    UnloadTexture(unloadTextures.GermanyLandmark);
    UnloadTexture(unloadTextures.GreeceLandmark);
    UnloadTexture(unloadTextures.ItalyLandmark);
    UnloadTexture(unloadTextures.SpainLandmark);
    UnloadTexture(unloadTextures.TurkeyLandmark);
    UnloadTexture(unloadTextures.NorwayLandmark);
    UnloadTexture(unloadTextures.EnglandLandmark);

    // Unload Others

    UnloadTexture(unloadTextures.settingsIcon);
    UnloadTexture(unloadTextures.closeSettingsIcon);
    UnloadTexture(unloadTextures.wheatIcon);
    UnloadTexture(unloadTextures.chain);
    UnloadTexture(unloadTextures.gameRight);
    UnloadTexture(unloadTextures.gameLeft);
    UnloadTexture(unloadTextures.armStageOne);
    UnloadTexture(unloadTextures.armStageTwo);
    UnloadTexture(unloadTextures.norwayArmS1);
    UnloadTexture(unloadTextures.norwayArmS2);
    UnloadTexture(unloadTextures.dart);
    UnloadTexture(unloadTextures.miniDart);
    UnloadTexture(unloadTextures.flyingCowRight);
    UnloadTexture(unloadTextures.flyingCowLeft);

    UnloadTexture(unloadTextures.fallingCowLeft);
    UnloadTexture(unloadTextures.fallingCowRight);

    UnloadTexture(unloadTextures.fallenCowLeft);
    UnloadTexture(unloadTextures.fallenCowRight);
}