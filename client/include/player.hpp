#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>



class Player : public sf::Drawable, public sf::Transformable{
public:
  Player();


public:
  void move(sf::Time timep);

private:
  float player_speed{200.0};


  // Virtual functions private
private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;



private:
  sf::RectangleShape player_body_temp;
  float player_x_size{};
  float player_y_size{};
};
