#include "Main.h"

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

    ofstream saveData;
    ifstream getData;

    GetData(getData, game, lockedCountries);

    PlayMusicStream(textures.menuMusic);
    SetMusicVolume(textures.menuMusic, settings.musicVolume);
    SetSoundVolume(textures.clickSound, settings.soundVolume);


    while (!WindowShouldClose() && !menu.isGameClosed)
    {
        BeginDrawing();

        ClearBackground(WHITE);

            Menu(menu, map, game, lockedCountries, textures, font);

            Game(settings, menu, map, game, lockedCountries, textures, font);

            Settings(settings, menu, map, game, textures, font);
        
        DrawFPS(10, 960);

        EndDrawing();
    }

    SaveData(saveData, game, lockedCountries);

    UnloadAllTextures(textures);

    UnloadFont(font);

    UnloadMusicStream(textures.menuMusic);

    CloseAudioDevice();

    CloseWindow();
}