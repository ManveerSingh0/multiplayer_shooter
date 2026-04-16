#include <iostream>
#include "raylib.h"


int main() {
  InitWindow(800, 450, "raylib - basic window");
  SetTargetFPS(60); // Set game to 60 FPS

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();
}
