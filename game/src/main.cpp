#include "Main.h"
#include "CrazyCow.h"

int main()
{
    srand(time(NULL));

    InitWindow(screenWidth, screenHeight, "CrazyCow");
    InitAudioDevice();
    SetExitKey(KEY_BACKSPACE);

    SetTargetFPS(60);

    Font font = LoadFont("../src/assets/Others/pixantiqua.png");

    AllTextures textures;

    SettingsS settings;

    MenuS menu;

    MapS map;

    GameS game;

    LockedCountries lockedCountries;

    FlyingCows cows;

    ofstream saveData;
    ifstream getData;

    GetData(getData, cows, game, lockedCountries);

    PlayMusicStream(textures.menuMusic);
    SetMusicVolume(textures.menuMusic, settings.musicVolume);
    SetSoundVolume(textures.clickSound, settings.soundVolume);


    while (!WindowShouldClose() && !menu.isGameClosed)
    {
        BeginDrawing();

        ClearBackground(WHITE);

            Menu(cows, menu, map, game, lockedCountries, textures, font);

            Game(settings, menu, map, game, lockedCountries, textures, font);

            if (!game.isQuizOpened && !game.isGameOpened)
            {
                OpenCrazyCow(cows, game, menu, map, textures, font);
            }
            
            CrazyCow(cows, game, menu, textures, font);

            Settings(settings, cows, menu, map, game, textures, font);
        
        DrawFPS(10, 960);

        EndDrawing();
    }

    SaveData(saveData, cows, game, lockedCountries);

    UnloadAllTextures(textures);

    UnloadFont(font);

    UnloadMusicStream(textures.menuMusic);

    CloseAudioDevice();

    CloseWindow();
}