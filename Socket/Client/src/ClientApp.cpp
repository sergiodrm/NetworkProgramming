#include <WinSock2.h>
#include <cstdio>
#include <iostream>
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
  inet_pton(AF_INET, "10.4.1.17", &xSockAddr.sin_addr);
  xSockAddr.sin_port = htons(9999);
  memset(xSockAddr.sin_zero, 0, 8);

  if (connect(xSocket, reinterpret_cast<SOCKADDR*>(&xSockAddr), sizeof(xSockAddr)) == -1)
  {
    printf("Connection failed!!!\n");
    return -1;
  }

  char buffer[1024];
  int length;
  do
  {
    printf("Text to send (\"exit\" to stop connection): ");
    //std::cin >> buffer;
    fgets(buffer, 1023, stdin);
    length = send(xSocket, buffer, strlen(buffer), 0);
  }
  while (length != -1 && strcmp(buffer, "exit\n") != 0);

  closesocket(xSocket);

  return 0;
}
