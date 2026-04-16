#include <sys/socket.h>



int main() {
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
}
