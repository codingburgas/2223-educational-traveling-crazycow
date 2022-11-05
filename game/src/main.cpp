#include "Functions.h"

const int screenWidth = 1920;
const int screenHeight = 1000;


int main()
{
    InitWindow(screenWidth, screenHeight, "GeoGame");
    SetTargetFPS(240);

    Variables Var;
    AllTextures textures;
    Animation animation;

    while (!WindowShouldClose() && !Var.bools.isGameClosed)
    {
        BeginDrawing();

        ClearBackground(WHITE);

        Menu(&Var.bools.isGameClosed, &Var.bools.areSettingsOpen, &Var.bools.isMenuOpen, &Var.ints.countryNumber,
            &Var.bools.chooseCountry, &Var.ints.BusX, &Var.ints.BusY, &Var.ints.BGX, textures, animation);

        EndDrawing();

        system("CLS");
    }
    unloadAllTextures(textures);
    //unloadAllAnimations(animation);

    CloseWindow();
}