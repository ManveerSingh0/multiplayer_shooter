#pragma once
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <player.h>



class Game {
public:
  Game(int width, int height, const std::string& title);
  ~Game();
  void run();


private:
  void game_loop();
  bool create_window(int height, int width, const std::string& title);
  void game_end();
  void talk_to_server(const Player& p);


private:
  int width{};
  int height{};
  int sockfd{};
  struct sockaddr_in server_addr{};
  std::string coordination{};
  const std::string title{};
};
