#include "Main.h"

const int screenWidth = 1920;
const int screenHeight = 1000;


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


    PlayMusicStream(textures.menuMusic);
    SetMusicVolume(textures.menuMusic, settings.musicVolume);
    SetSoundVolume(textures.clickSound, settings.soundVolume);

    

    while (!WindowShouldClose() && !menu.isGameClosed)
    {
        BeginDrawing();

        ClearBackground(WHITE);

            Menu(settings, menu, map, textures, font);

            Game(settings, menu, map, game, lockedCountries, textures, font);

            Settings(settings, menu, map, game, textures, font);
        
        DrawFPS(10, 960);

        EndDrawing();
    }

    UnloadAllTextures(textures);
    UnloadFont(font);

    StopMusicStream(textures.menuMusic);

    CloseAudioDevice();
    CloseWindow();
}