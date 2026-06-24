#include <SFML/Graphics.hpp>
#include <game.hpp>
#include <iostream>

int main() {
  Game game("still working" , {800,800});
  game.main_loop();
}
