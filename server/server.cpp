#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>





void datagram_recv(const int sockfd,  sockaddr* addr, socklen_t size) {
  char mesg[1024]; 
  int char_mesg_size{1024};


  for (;;) {
    int n = recvfrom(sockfd, mesg, char_mesg_size,0,addr,&size);

    if (n > 0) {
      mesg[char_mesg_size] = '\0';
      std::cout << mesg << '\n';
    }
  }
}


int main() {
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  struct sockaddr_in addr{};

  addr.sin_family = AF_INET;
  addr.sin_port = htons(8080);
  inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

  if (bind(sockfd, reinterpret_cast<sockaddr *>(&addr), sizeof(addr)) < 0) {
    std::cout << "error here\n";
  }



  struct sockaddr_in client;
  socklen_t size = sizeof(client);
  datagram_recv(sockfd, reinterpret_cast<sockaddr*>(&client), size);
}
