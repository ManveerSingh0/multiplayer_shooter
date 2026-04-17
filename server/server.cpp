#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <map>
#include <string>
#include <nlohmann/json.hpp>





// this function will convert given ip address to unique_id
// Signature: sockaddr -> bool
// interp. sockaddr is a struct , which holds ip address, family , port number.
//         this function will convert given ip address to unique id

/*
  bool unique_id_converter(const sockaddr* addr, n){
    return false;
  }
*/




int main() {
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  sockaddr_in addr{};
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8080);
  inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

  if (bind(sockfd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) < 0) {
    std::cout << "bind error\n";
    return 1;
  }

  char game_buff[1024];
  struct sockaddr_in client_sockaddress{};
  size_t size{1024};
  socklen_t addrlen{sizeof(client_sockaddress)};

  static int u_id{};

  
  std::map<std::string , sockaddr_in> unique_id_map;

  for (;;) {
    // we receive the data first;
    int n = recvfrom(sockfd, game_buff, size, 0,reinterpret_cast<sockaddr*>(&client_sockaddress), &addrlen);

    // convert it to unique_id 
    // using function is better to convert to unique_id

    // game_buff[n] = '\0';

    // if (n > 0) {
    //   std::cout << game_buff << '\n';
    // }

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
