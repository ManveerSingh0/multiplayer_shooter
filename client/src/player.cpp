#include <player.hpp>



Player::Player(){ 
  player_x_size = 100.0f;
  player_y_size = 100.0f;



  player_body_temp.setSize(sf::Vector2f{player_x_size, player_y_size});
  player_body_temp.setFillColor(sf::Color::Red);
  player_body_temp.setOrigin(sf::Vector2f{(player_x_size / 2.0f) , (player_y_size / 2.0f)});
  player_body_temp.setPosition(sf::Vector2f{200.0f,200.0f});
}



void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();
  target.draw(player_body_temp,states);
}
