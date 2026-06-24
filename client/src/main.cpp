#include <SFML/Graphics.hpp>
#include <game.hpp>
#include <iostream>

int main() {
  Game game("Multiplayer shooter" , {800,800});
  game.main_loop();
}
