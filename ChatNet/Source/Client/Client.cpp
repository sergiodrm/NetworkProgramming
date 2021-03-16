// Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>

#include "Net/factoryenet.h"
#include "Net/buffer.h"

namespace
{
  const int s_port = 65785;

  enum class EMessageType
  {
    SetID,
    SetName,
    Message
  };

  Net::NetID s_clientID = 0;
  std::map<Net::NetID, char*> s_idNames;
}

int main()
{
  // Create the factory
  Net::CFactory* pFactory = new Net::CFactoryEnet();

  // Build a client and set it
  Net::CClient* pClient = pFactory->buildClient();
  pClient->init(1);

  // Ask for a server IP
  printf("Write the server IP: ");
  char msg[1024];
  fgets(msg, 12, stdin);
  Net::CConnection* pConnection = pClient->connect(msg, s_port, 0, 5000u);

  // Create server packets
  std::vector<Net::CPacket*> packets;

  // Once the connection succeeds, read the log in messages from server
  bool bIsIDSet = false;
  do
  {
    pClient->service(packets);
    for (Net::CPacket* packet : packets)
    {
      switch (packet->getType())
      {
      case Net::EPacketType::DATA:
        {
          // Read received data
          Net::CBuffer data;
          data.write(packet->getData(), packet->getDataLength());
          data.reset();

          // Check data
          EMessageType eType;
          data.read(&eType, sizeof(eType));
          if (eType == EMessageType::SetID)
          {
            // Server sent us our ID client
            data.read(&s_clientID, sizeof(s_clientID));
            bIsIDSet = true;
          }
        }
        break;
      }
    }
  }
  while (!bIsIDSet);

  // We have an ID, but we need a nick to the client user

  printf("Write your nick: ");
  fgets(msg, 1023, stdin);
  char* endLine = strchr(msg, '\n');
  *endLine = '\0';
  Net::CBuffer data;
  EMessageType eMessageType = EMessageType::SetName;
  data.write(&eMessageType, sizeof(eMessageType));
  data.write(&s_clientID, sizeof(s_clientID));
  data.write(msg, strlen(msg));
  Net::CPacket packet(Net::EPacketType::DATA, data.getData(), data.getSize(), pConnection, 0);
  pClient->sendData(pConnection, packet.getData(), packet.getDataLength(), 0, true);

  printf("Client id sent to server: [#%d] %s\n", s_clientID, msg);


  // Client loop
  printf("Write text to send (\"exit\" to close connection):\n");
  do
  {
    // Read server packets
    pClient->service(packets);
    for (Net::CPacket* packet : packets)
    {
      switch (packet->getType())
      {
      case Net::CONNECTION:
        {
          printf("You has been connected successfully!\n");
        }
        break;
      case Net::DATA:
        {
          Net::CBuffer data;
          data.write(packet->getData(), packet->getDataLength());
          data.reset();
          // Read message type
          EMessageType eMessageType;
          data.read(&eMessageType, sizeof(eMessageType));
          // Read client id
          Net::NetID clientIDMessage;
          data.read(&clientIDMessage, sizeof(clientIDMessage));

          // Read the rest of the message
          size_t length = data.getSize() - sizeof(eMessageType) - sizeof(clientIDMessage);
          data.read(msg, length);
          msg[length] = '\0';

          switch (eMessageType)
          {
          case EMessageType::Message:
            {
              printf("[Client %d:%s] Received text: %s\n", clientIDMessage, s_idNames[clientIDMessage], msg);
            }
            break;
          case EMessageType::SetName:
            {
              printf("[Client %d] Change name to %s\n", clientIDMessage, msg);
              size_t copySize = strlen(msg) + 1;
              s_idNames[clientIDMessage] = new char[copySize];
              strcpy_s(s_idNames[clientIDMessage], copySize, msg);
            }
            break;
          default: break;
          }

          printf("Message from server: %s\n", msg);
        }
        break;
      case Net::DISCONNECTION:
        {
          printf("You has been disconnected\n");
        }
        break;
      default: break;
      }
    }
    // Clear packets
    packets.clear();

    // Send client data

    // Give me the message
    fgets(msg, 1023, stdin);

    // Find end line and change it
    char* endLine = strchr(msg, '\n');
    *endLine = '\0';

    if (strcmp(msg, "exit") != 0)
    {
      Net::CBuffer data;
      eMessageType = EMessageType::Message;
      data.write(&eMessageType, sizeof(eMessageType));
      data.write(&s_clientID, sizeof(s_clientID));
      data.write(msg, strlen(msg));
      Net::CPacket messagePacket(Net::EPacketType::DATA, data.getData(), data.getSize(), pConnection, 0);
      pClient->sendData(pConnection, messagePacket.getData(), messagePacket.getDataLength(), 0, true);
    }
  }
  while (strcmp(msg, "exit") != 0);

  printf("Closing client app\n");

  // Clear pointers
  pClient->release();
  delete pClient;
  delete pFactory;

  return 0;
}
