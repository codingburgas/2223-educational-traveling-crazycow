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

    Variables Var;
    AllTextures textures;

    PlayMusicStream(textures.menuMusic);
    SetMusicVolume(textures.menuMusic, Var.nums.musicVolume);
    SetSoundVolume(textures.clickSound, Var.nums.soundVolume);

    while (!WindowShouldClose() && !Var.bools.isGameClosed)
    {
        BeginDrawing();

        ClearBackground(WHITE);

        Menu(&Var.bools.isGameClosed, &Var.bools.isMenuOpen, &Var.bools.openMap, &Var.nums.BusX, &Var.nums.BusY, &Var.nums.BGX,
             &Var.nums.countryNumber, textures, font);

        Game(&Var.bools.openMap, &Var.nums.countryNumber, &Var.nums.countryHover, &Var.bools.countryList, &Var.nums.mapLocation,
             &Var.bools.areSettingsOpen, &Var.nums.money, &Var.nums.trueQuestionCounter, &Var.nums.questionsNumberCounter,
             &Var.nums.randomQuestion, &Var.bools.isMenuOpen, &Var.bools.isQuizOpened, &Var.bools.isAnswered, &Var.bools.isWarningOpen,
             &Var.bools.openQuiz, &Var.bools.openGame, &Var.bools.isGameOpened, textures, font, &Var.countryAccessibility);

        Settings(&Var.bools.areSettingsOpen, &Var.bools.isMenuOpen, &Var.bools.openMap, &Var.nums.countryNumber, &Var.nums.questionsNumberCounter,
                 &Var.bools.isQuizOpened, &Var.nums.randomQuestion, &Var.bools.isAnswered, &Var.bools.isEscapeReleased, &Var.nums.musicVolume,
                 &Var.nums.soundVolume, textures, font);

        DrawFPS(10, 960);

        EndDrawing();
    }
    UnloadAllTextures(textures);
    UnloadFont(font);

    StopMusicStream(textures.menuMusic);

    CloseAudioDevice();
    CloseWindow();
}