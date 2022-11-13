#include "Functions.h"

const int screenWidth = 1920;
const int screenHeight = 1000;


int main()
{
    srand(time(NULL));

    InitWindow(screenWidth, screenHeight, "GeoGame");
    SetExitKey(KEY_BACKSPACE);

    SetTargetFPS(60);

    Font font = LoadFont("../src/assets/Others/pixantiqua.png");

    Variables Var;
    AllTextures textures;

    while (!WindowShouldClose() && !Var.bools.isGameClosed)
    {
        BeginDrawing();

        ClearBackground(WHITE);

        Menu(&Var.bools.isGameClosed, &Var.bools.isMenuOpen, &Var.bools.openMap, &Var.ints.BusX, &Var.ints.BusY, &Var.ints.BGX,
             &Var.ints.countryNumber, textures, font);

        Game(&Var.bools.openMap, &Var.ints.countryNumber, &Var.ints.countryHover, &Var.bools.countryList, &Var.ints.mapLocation,
             &Var.bools.areSettingsOpen, &Var.ints.money, &Var.ints.trueQuestionCounter, &Var.ints.questionsNumberCounter,
             &Var.ints.randomQuestion, &Var.bools.isMenuOpen, &Var.bools.isQuizOpened, &Var.bools.isAnswered, textures, font, &Var.countryBools);

        Settings(&Var.bools.areSettingsOpen, &Var.bools.isMenuOpen, &Var.bools.openMap, &Var.ints.countryNumber, &Var.ints.questionsNumberCounter,
                 &Var.bools.isQuizOpened, &Var.ints.randomQuestion, &Var.bools.isAnswered, textures, font);

        DrawFPS(10, 960);

        EndDrawing();
    }
    UnloadAllTextures(textures);
    UnloadFont(font);

    CloseWindow();
}