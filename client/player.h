#pragma once
#include <raylib.h>

class Player {
 public:
  Player(int,int,int,int);
   ~Player();

   void draw_player();
   void player_move();


  int get_x()const;
   int get_y()const;

 private:
   Rectangle player;
   int player_speed{100};

   int x , y , height, width; // player coordinates and size


 private:
   void set_size(int width, int height);
   void set_position(int x, int y);
};
