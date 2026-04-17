#include <player.h>



// Signature int , int , int , int -> Player
// inerp. create player with (x,y) position with size (height, width)
// Parameters:
//           x  -  horizontal position in pixel from left edge
//           y  - vertical position in pixel from top edge
//           height - player rectangle height in pixels
//           width - player rectangle width in pixels 
Player::Player(int x, int y, int width, int height)
  :x{x},y{y},height{height},width{width}{

  set_position(x , y);
  set_size(width, height);
}
Player::~Player() {
  
}

int Player::get_x() const{ return player.x; }
int Player::get_y() const{return player.y;}


void Player::set_size(int height, int width) {
  player.height = height;
  player.width = width;
}



void Player::set_position(int x, int y) {
  player.x = x;
  player.y = y;
}

void Player::draw_player() {
  DrawRectangleRec(player, RED);
}


void Player::player_move() {
  if(IsKeyDown(KEY_W)){
    player.y -= GetFrameTime() * player_speed;
  }
  if(IsKeyDown(KEY_S)){
    player.y += GetFrameTime() * player_speed;
  }
  if(IsKeyDown(KEY_A)){
    player.x -= GetFrameTime() * player_speed;
  }
  if(IsKeyDown(KEY_D)){
    player.x += GetFrameTime() * player_speed;
  }
}

