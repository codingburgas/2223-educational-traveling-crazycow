#include "raylib.h"

int main(void)
{
    const int screenWidth = 1920;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - gif playing");

    Texture2D tex = LoadTexture("../src/assets/van.png");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(tex, 100, 100, WHITE);

        EndDrawing();
    }

    CloseWindow();
}