#include <WinSock2.h>
#include <cstdio>


int main()
{
  // Init library
  WSADATA xWsaData;
  WSAStartup(MAKEWORD(2, 0), &xWsaData);

  // Create a socket
  SOCKET xSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  // Bind socket
  struct sockaddr_in xLocal;
  xLocal.sin_family = AF_INET;
  xLocal.sin_addr.s_addr = INADDR_ANY;
  xLocal.sin_port = htons(9999);
  memset(xLocal.sin_zero, 0, 8);

  if (bind(xSocket, reinterpret_cast<SOCKADDR*>(&xLocal), sizeof(xLocal)) == -1)
  {
    printf("Binding error!\n");
    return -1;
  }

  // Start to listen...
  if (listen(xSocket, 1) == -1)
  {
    printf("Listening error...\n");
    return -1;
  }

  printf("Waiting connections...\n");
  int sockAddrLength = sizeof(xLocal);
  xSocket = accept(xSocket, reinterpret_cast<SOCKADDR*>(&xLocal), &sockAddrLength);

  printf("Connection done. Receiving text.\n");

  // Listening loop
  char buffer[1024];
  int length;
  do
  {
    // Received
    length = recv(xSocket, buffer, 1023, 0);

    // Check message
    if (length > 0)
    {
      // Specified the end of the buffer
      buffer[length] = '\0';
      printf("Received text: %s\n", buffer);
    }
  }
  while (length > 0 && strcmp(buffer, "exit\n") != 0);

  closesocket(xSocket);

  return 0;
}
