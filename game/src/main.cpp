#include "Include.h"
#include "CrazyCow.h"

int main()
{
    srand((unsigned int)time(NULL));

    // initializing a window

    InitWindow(screenWidth, screenHeight, "CrazyCow"); 

    // initializing an audio defice

    InitAudioDevice(); 

    // set a EXIT key default value

    SetExitKey(KEY_BACKSPACE); 

    // set a FPS default value

    SetTargetFPS(60); 
    
    // Makeing the main structure type variable of the game

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

    // gets the data used before

    GetData(getData, cows, map, game, lockedCountries);  

    // Play the music stream

    PlayMusicStream(textures.menuMusic);  

    // sets the music a default value

    SetMusicVolume(textures.menuMusic, settings.musicVolume);   

    // sets the sound a default value

    SetSoundVolume(textures.clickSound, settings.soundVolume);               

    // loop while the window is closed

    while (!WindowShouldClose() && !menu.isGameClosed)                    
    {
        // start drawing

        BeginDrawing();        
        
        // clears the background

        ClearBackground(WHITE);                                             

            Menu(cows, menu, map, game, lockedCountries, textures, font);

            Game(settings, menu, map, game, lockedCountries, textures, font);

            CrazyCow(cows, map, game, menu, textures, font);

            FinishTheGame(map, menu, game, textures, font);

            Settings(settings, cows, menu, map, game, textures, font);

        // draws the FPS

        DrawFPS(10, 960);
                                                   
        // stop drawing

        EndDrawing();                                                      
    }

    // saves the data that is changed

    SaveData(saveData, cows, map, game, lockedCountries); 

    // unload all textures

    UnloadAllTextures(textures);       

    // unload the font

    UnloadFont(font);           

    // unload the music stream

    UnloadMusicStream(textures.menuMusic);   

    // close the audio device

    CloseAudioDevice();         

    // close the window

    CloseWindow();  
}