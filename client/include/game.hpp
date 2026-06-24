#pragma once



#include <SFML/System/Time.hpp>
#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <player.hpp>




class Game {
public:
  //This constructor will set the basic of SFML window (name , size) 
  Game(std::string bwindow_name,  sf::Vector2<uint> size);
  ~Game();
  void main_loop();

private:
  void process_events();
  void game_render();
  

private:
  Player m_player;
  sf::Clock clock;
  sf::Time elapsed_time;
  sf::RenderWindow window{};
  std::string m_window_name{};
};

