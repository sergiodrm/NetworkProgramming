// Fill out your copyright notice in the Description page of Project Settings.


#include "GameNet/GameNetManager.h"
#include "CarsGameInstance.h"
#include "GameBuffer.h"
#include "NetComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Net/buffer.h"
#include "Net/packet.h"
#include "Game/Car.h"

CGameNetManager::CGameNetManager(UCarsGameInstance* GameInstance)
    : GameInstanceOwner(GameInstance), NetManager(nullptr), MapLoadedNotifications(0)
{
    // Init net manager and save it
    Net::CManager::Init();
    NetManager = Net::CManager::getSingletonPtr();

    // We want to be an observer
    NetManager->addObserver(this);
}

CGameNetManager::~CGameNetManager()
{
    // Remove observer connections
    NetManager->removeObserver(this);

    // End net manager
    NetManager = nullptr;
    Net::CManager::Release();
}

void CGameNetManager::dataPacketReceived(Net::CPacket* packet)
{
    CGameBuffer DataBuffer;
    DataBuffer.write(packet->getData(), packet->getDataLength());
    DataBuffer.reset();

    Net::NetMessageType MessageType;
    DataBuffer.read(MessageType);
    switch (MessageType)
    {
    case Net::NetMessageType::LOAD_MAP: // Client side
        {
            char Level[64];
            DataBuffer.read(Level);
            UGameplayStatics::OpenLevel(GameInstanceOwner->GetWorld(), Level);

            CGameBuffer DataBuffer2;
            DataBuffer2.write(Net::NetMessageType::MAP_LOADED);
            NetManager->send(&DataBuffer2, true);
        }
        break;
    case Net::NetMessageType::MAP_LOADED: // Server side
        {
            MapLoadedNotifications++;
            if (MapLoadedNotifications >= NetManager->getConnections().size())
            {
                for (auto& client : NetManager->getConnections())
                {
                    CGameBuffer LoadCarDataBuffer;
                    LoadCarDataBuffer.write(Net::NetMessageType::LOAD_PLAYER);
                    LoadCarDataBuffer.write(client.first);
                    FVector initPosition(220.f, -310.f + 40.f * client.first, 0.f);
                    LoadCarDataBuffer.write(initPosition);

                    CreateCar(client.first, initPosition);

                    NetManager->send(&LoadCarDataBuffer, true);
                }
            }
        }
        break;
    case Net::NetMessageType::LOAD_PLAYER: // Client side
        {
            unsigned int client;
            FVector initPosition;
            DataBuffer.read(client);
            DataBuffer.read(initPosition);
            CreateCar(client, initPosition);

            if (client == NetManager->getID())
            {
                APlayerController* PlayerController = GEngine->GetFirstLocalPlayerController(
                    GameInstanceOwner->GetWorld());
                if (PlayerController)
                {
                    ACar* ourCar = Players[client];
                    PlayerController->Possess(ourCar);
                }
            }
        }
        break;
    case Net::NetMessageType::ENTITY_MSG:
        {
            unsigned int client;
            DataBuffer.read(client);

            if (client != NetManager->getID())
            {
                ACar* clientCar = Players[client];
                clientCar->GetNetComponent()->DeserializeData(DataBuffer);
                if (NetManager->getID() == Net::ID::SERVER)
                {
                    NetManager->send(&DataBuffer, false);
                }
            }
        }
        break;
    }
}

void CGameNetManager::connectionPacketReceived(Net::CPacket* packet)
{
    if (NetManager->getID() == Net::ID::SERVER)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Client connected"));
        }
    }
}

void CGameNetManager::disconnectionPacketReceived(Net::CPacket* packet) {}


void CGameNetManager::CreateCar(unsigned id, const FVector& initPosition)
{
    FActorSpawnParameters SpawnParameters;
    SpawnParameters.Name = FName("Car", id);
    SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    ACar* car = GameInstanceOwner->GetWorld()->SpawnActor<ACar>(initPosition, FRotator::ZeroRotator, SpawnParameters);
    if (car)
    {
        Players[id] = car;
        PlayersId[car] = id;
    }
}

ACar* CGameNetManager::GetOwnCar() const
{
    if (NetManager->getID() != Net::ID::SERVER)
    {
        return Players.at(static_cast<unsigned>(NetManager->getID()));
    }
    return nullptr;
}

unsigned CGameNetManager::GetCarId(ACar* car) const
{
    return PlayersId.at(car);
}
