#include "Functions.h"

const int screenWidth = 1920;
const int screenHeight = 1000;


int main()
{
    InitWindow(screenWidth, screenHeight, "GeoGame");
    SetTargetFPS(240);

    Variables Var;
    AllTextures textures;

    while (!WindowShouldClose() && !Var.bools.isGameClosed)
    {
        BeginDrawing();

        ClearBackground(WHITE);

        Menu(&Var.bools.isGameClosed, &Var.bools.isMenuOpen, &Var.bools.chooseCountry, &Var.ints.BusX, &Var.ints.BusY, &Var.ints.BGX, textures);

        Game(&Var.bools.chooseCountry, &Var.ints.countryNumber, &Var.bools.countryList, textures);

        Settings(&Var.bools.areSettingsOpen, &Var.bools.isMenuOpen, &Var.bools.chooseCountry, textures);

        EndDrawing();

        system("CLS");
    }
    unloadAllTextures(textures);

    CloseWindow();
}