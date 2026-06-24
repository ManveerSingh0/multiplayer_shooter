#include <SFML/System/Time.hpp>
#include <game.hpp>
#include <iostream>


Game::Game(std::string window_name, const sf::Vector2<uint> size){
  window.create(sf::VideoMode(size),window_name);
}

Game::~Game() {
  window.close();
}



////////////////////
//    Main Loop   // 
////////////////////
void Game::main_loop() {
  while (window.isOpen()) {
    elapsed_time = clock.restart(); 


    process_events();
    game_render();
  }
}





void Game::game_render() {
  window.clear();
  window.draw(m_player);
  window.display();
}




void Game::process_events() {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
	window.close();
      }
    }  
}


