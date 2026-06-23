#pragma once



#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>


class Game {
public:
  //This constructor will set the basic of SFML window (name , size) 
  Game(std::string bwindow_name,  sf::Vector2<uint> size);

private:
  // sf::RenderWindow window{};
  // std::string m_window_name{};
};

