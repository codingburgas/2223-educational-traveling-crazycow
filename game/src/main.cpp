#include "Functions.h"

const int screenWidth = 1920;
const int screenHeight = 1000;


int main()
{
    InitWindow(screenWidth, screenHeight, "GeoGame");
    SetExitKey(KEY_BACKSPACE);
    SetTargetFPS(240);

    Font font = LoadFont("../src/assets/pixantiqua.png");

    Variables Var;
    AllTextures textures;

    while (!WindowShouldClose() && !Var.bools.isGameClosed)
    {
        BeginDrawing();

        ClearBackground(WHITE);

        Menu(&Var.bools.isGameClosed, &Var.bools.isMenuOpen, &Var.bools.openMap, &Var.ints.BusX, &Var.ints.BusY, &Var.ints.BGX, textures, font);

        Game(&Var.bools.openMap, &Var.ints.countryNumber, &Var.ints.countryHover, &Var.bools.countryList, &Var.ints.mapLocation, textures, font);

        Settings(&Var.bools.areSettingsOpen, &Var.bools.isMenuOpen, &Var.bools.openMap, textures, font);

        EndDrawing();

        system("CLS");
    }
    UnloadAllTextures(textures);
    UnloadFont(font);

    CloseWindow();
}