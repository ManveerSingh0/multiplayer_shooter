#include <game.h>
#include <player.h>
#include <raylib.h>
#include <string>
#include <nlohmann/json.hpp>



Game::Game(int width, int height, const std::string& title)
    : width{width}, height{height}, title{title} {

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
}

Game::~Game() {
    game_end();
}

void Game::run
() {
  game_loop();
}


void Game::talk_to_server(const Player& p) {
  nlohmann::json j;
  j["x"] = p.get_x();
  j["y"] = p.get_y();

  coordination = j.dump();


  sendto(sockfd, coordination.data(), coordination.size(), 0, reinterpret_cast<sockaddr*>(&server_addr),sizeof(server_addr));  
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
    talk_to_server(p);

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


