#include <SFML/Window/Keyboard.hpp>
#include <player.hpp>



Player::Player(){ 
  player_x_size = 100.0f;
  player_y_size = 100.0f;


  player_body_temp.setSize(sf::Vector2f{player_x_size, player_y_size});
  player_body_temp.setFillColor(sf::Color::Red);
  player_body_temp.setOrigin(sf::Vector2f{(player_x_size / 2.0f) , (player_y_size / 2.0f)});
}



void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();
  target.draw(player_body_temp,states);
}


void Player::move(sf::Time time){
  sf::Vector2f direction{0.f, 0.f};
  

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)){
    direction.x -= 10.0f;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)){
    direction.x += 10.0f;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)){
    direction.y -= 10.0f;   
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)){
    direction.y += 10.0f;
  }

  
  sf::Vector2f current_pos = player_body_temp.getPosition();
  player_body_temp.setPosition(current_pos + direction * player_speed * time.asSeconds());
}
