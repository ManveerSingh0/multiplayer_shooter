#include <game.h>
#include <player.h>
#include <raylib.h>
#include <string>

Game::Game(int width, int height, const std::string& title)
    : width{width}, height{height}, title{title} {
}

Game::~Game() {
    game_end();
}

void Game::run
() {
  game_loop();
}



// Signature:  void -> void
// Main loop of the game keeps the window  alive until closed
/*
  void Game::game_loop(){
    return;
  }
 */

void Game::game_loop() {
  create_window(width, height, title);

  Player p(10,10,100,100);
  char fps[20];

  while (!WindowShouldClose()) {
    snprintf(fps , sizeof(fps), "FPS: %d", GetFPS());

    //Moves the player IsKeyDown function by 100 speed
    p.player_move(); 

    BeginDrawing();
    ClearBackground(BLACK);
    DrawText(fps, 10,10, 30, RED);

    // Player function To Draw player
    // using DrawRectangleRec function 
    p.draw_player();
    EndDrawing();



  }
}


// Signature: Integer , Integer , String -> Bool
// Interp. creates a window by given width , height and title
//         return true if window is created

// Example:
// create_window(100,100,"title") -> true
// create_window(-1,100,"title") -> false

bool Game::create_window(int height , int width, const std::string& title ) {
  if(width < 0 || height < 0){return false;}

  InitWindow(width, height, title.data());

  return true;
}


// Signature: void -> void
// Closes the window when Game's Destructor is called
void Game::game_end() {
  CloseWindow();
}


