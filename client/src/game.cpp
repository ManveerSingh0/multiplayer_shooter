#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <game.hpp>



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
    this->update();
    game_render();
  }
}

void Game::update() {
  m_player.move(elapsed_time);
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
      if (auto const *key_pressed = event->getIf<sf::Event::KeyPressed>()) {
        if (key_pressed->scancode == sf::Keyboard::Scancode::Escape) {
	  window.close(); 
        }
      }
    }  
}


