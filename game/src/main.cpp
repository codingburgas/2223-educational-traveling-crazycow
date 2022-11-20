#include "Include.h"
#include "CrazyCow.h"

int main()
{
    srand((unsigned int)time(NULL));

    InitWindow(screenWidth, screenHeight, "CrazyCow"); // initializing a window
    InitAudioDevice(); // initializing an audio defice
    SetExitKey(KEY_BACKSPACE); // set a EXIT key default value

    SetTargetFPS(60); // set a FPS default value
    
    // Makeing the main structure type variable of the game ---------------------------------
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

    // ----------------------------------------------------------------------------------------

    GetData(getData, cows, game, lockedCountries);                      // gets the data used before

    PlayMusicStream(textures.menuMusic);                                     // Play the music stream
    SetMusicVolume(textures.menuMusic, settings.musicVolume);                 // sets the music a default value
    SetSoundVolume(textures.clickSound, settings.soundVolume);               // sets the sound a default value


    while (!WindowShouldClose() && !menu.isGameClosed)                     // loop while the window is closed
    {
        BeginDrawing();                                                    // start drawing

        ClearBackground(WHITE);                                             // clears the background

            Menu(cows, menu, map, game, lockedCountries, textures, font);

            Game(settings, menu, map, game, lockedCountries, textures, font);

            if (!game.isQuizOpened && !game.isGameOpened)
            {
                OpenCrazyCow(cows, game, menu, map, textures, font);
            }
            
            CrazyCow(cows, game, menu, textures, font);

            Settings(settings, cows, menu, map, game, textures, font);
        
        DrawFPS(10, 960);                                                   // draws the FPS

        EndDrawing();                                                      // stop drawing
    }

    SaveData(saveData, cows, game, lockedCountries);              // saves the data that is changed

    UnloadAllTextures(textures);                                    // unload all textures

    UnloadFont(font);                                               // unload the font

    UnloadMusicStream(textures.menuMusic);                          // unload the music stream

    CloseAudioDevice();                                             // close the audio device

    CloseWindow();                                                  // close the window
}