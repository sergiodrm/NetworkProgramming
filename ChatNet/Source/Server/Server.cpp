// Server.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>


#include "Net/buffer.h"
#include "Net/factoryenet.h"

namespace
{
  const int s_port = 65785;

  enum class EMessageType
  {
    SetID,
    SetName,
    Message
  };

  Net::NetID s_NextID = 0;

  std::map<Net::NetID, char*> s_idNames;
}

int main()
{
  // Create a factory to make a server
  Net::CFactory* pFactory = new Net::CFactoryEnet();

  // Build server
  Net::CServer* pServer = pFactory->buildServer();
  pServer->init(s_port, 10);

  printf("Server listening\n");
  // Server loop
  std::vector<Net::CPacket*> packets;
  char msg[1024];
  do
  {
    // Give me the packets
    pServer->service(packets);

    // Process packets
    for (std::vector<Net::CPacket*>::iterator iterator = packets.begin(); iterator != packets.end(); ++iterator)
    {
      Net::CPacket* pPacket = *iterator;
      switch (pPacket->getType())
      {
      case Net::CONNECTION:
        {
          ++s_NextID;
          Net::CBuffer data;
          EMessageType eType = EMessageType::SetID;
          data.write(&eType, sizeof(eType));
          data.write(&s_NextID, sizeof(s_NextID));
          Net::CPacket packet(Net::EPacketType::DATA, data.getData(), data.getSize(), pPacket->getConnection(), 0);
          pServer->sendData(pPacket->getConnection(), packet.getData(), packet.getDataLength(), 0, true);
          printf("New client connection!\n");
        }
        break;
      case Net::DATA:
        {
          // We have to check the type of data which we have received
          Net::CBuffer data;
          data.write(pPacket->getData(), pPacket->getDataLength());
          data.reset();
          // Read message type
          EMessageType eMessageType;
          data.read(&eMessageType, sizeof(eMessageType));
          // Read client ID
          Net::NetID clientID;
          data.read(&clientID, sizeof(clientID));
          // Calculate the size of the rest of the packet
          size_t size = data.getSize() - sizeof(eMessageType) - sizeof(clientID);
          data.read(msg, size);
          msg[size] = '\0';

          // Interpret the msg
          switch (eMessageType)
          {
          case EMessageType::Message:
            {
              printf("[Client %d:%s] Received text: %s\n", clientID, s_idNames[clientID], msg);
            }
            break;
          case EMessageType::SetName:
            {
              // Resend all the clients to the new client to tell it the names
              for (auto& client : s_idNames)
              {
                Net::CBuffer data;
                EMessageType type = EMessageType::SetName;
                data.write(&type, sizeof(type));
                data.write(&client.first, sizeof(client.first));
                data.write(client.second, strlen(client.second));
                pServer->sendData(pPacket->getConnection(), data.getData(), data.getSize(), 0, true);
              }
              printf("[Client %d] Change name to %s\n", clientID, msg);
              size_t copySize = strlen(msg) + 1;
              s_idNames[clientID] = new char[copySize];
              strcpy_s(s_idNames[clientID], copySize, msg);
            }
            break;
          default: break;
          }

          // Resend to all
          pServer->sendAll(pPacket->getData(), pPacket->getDataLength(), 0, true);
        }
        break;
      case Net::DISCONNECTION:
        {
          printf("Client disconnected\n");
        }
        break;
      default: break;
      }
    }

    // Clear current packets
    packets.clear();
  }
  while (strcmp(msg, "close_server") != 0);

  printf("Closing server\n");

  pServer->release();
  delete pServer;
  delete pFactory;

  return 0;
}
