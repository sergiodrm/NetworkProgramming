#include <WinSock2.h>
#include <cstdio>
#include <WS2tcpip.h>

int main()
{
  // Init library
  WSADATA xWsaData;
  WSAStartup(MAKEWORD(2, 2), &xWsaData);

  // Create a socket
  SOCKET xSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (xSocket == -1)
  {
    printf("Error when creating client socket!!\n");
    return -1;
  }

  struct sockaddr_in xSockAddr;
  xSockAddr.sin_family = AF_INET;
  inet_pton(AF_INET, "127.0.0.1", &xSockAddr.sin_addr);
  xSockAddr.sin_port = htons(9999);
  memset(xSockAddr.sin_zero, 0, 8);

  if (connect(xSocket, reinterpret_cast<SOCKADDR*>(&xSockAddr), sizeof(xSockAddr)) == -1)
  {
    printf("Connection failed!!!\n");
    return -1;
  }


  return 0;
}
