#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <map>
#include <string>
#include <nlohmann/json.hpp>
#include <sys/epoll.h>


// Signature: void -> int
// purpose: creates udp server and binds the address to file descriptor.
//          returns a file descriptor created on success , -1 on failure; 

//this is the stub 
// int init_udp_server() {
//   return 0;
// }

//Example 1: on success  , the result should  be >= 0;
//Example 2: on failure  , the result should  be -1;
int init_udp_server() {
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  sockaddr_in addr{};
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8080);
  inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

  if (bind(sockfd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) < 0) {
    std::cout << "bind error\n";
    return 1;
  }
  return sockfd;
}



int main() {
  int sockfd = init_udp_server();


  char game_buff[1024];
  struct sockaddr_in client_sockaddress{};
  size_t size{1024};
  socklen_t addrlen{sizeof(client_sockaddress)};

  static int u_id{};

  
  std::map<std::string , sockaddr_in> unique_id_map;


  int epoll_fd = epoll_create1(0);
  struct epoll_event event;
  event.events = EPOLLIN;
  event.data.fd = sockfd;

  epoll_ctl(epoll_fd, EPOLL_CTL_ADD, sockfd, &event);
  

  for (;;) {
    // we receive the data first;
    int n = recvfrom(sockfd, game_buff, size, 0,reinterpret_cast<sockaddr*>(&client_sockaddress), &addrlen);


    std::string address_to_unique =
      std::string(inet_ntoa(client_sockaddress.sin_addr)) + ":" +
      std::to_string(ntohs(client_sockaddress.sin_port));


    unique_id_map[address_to_unique] = client_sockaddress;

    for (auto &[other_id, addr] : unique_id_map) {
      if (other_id != address_to_unique) {
	sendto(sockfd, game_buff, n , 0, reinterpret_cast<sockaddr*>(&addr), sizeof(addr));
      }
    }
  }
}
