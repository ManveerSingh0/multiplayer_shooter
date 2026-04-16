#pragma once
#include <string>

class Game {
public:
  Game(int width, int height, const std::string& title);
  ~Game();
  void run();
private:
  void game_loop();
  bool create_window(int height, int width, const std::string& title);
  void game_end();



private:
  int width{};
  int height{};
  const std::string title;
};
