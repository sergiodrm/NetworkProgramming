// Fill out your copyright notice in the Description page of Project Settings.


#include "GameNet/GameNetManager.h"
#include "CarsGameInstance.h"
#include "GameBuffer.h"
#include "Kismet/GameplayStatics.h"
#include "Net/buffer.h"
#include "Net/packet.h"

CGameNetManager::CGameNetManager(UCarsGameInstance* GameInstance)
    : GameInstanceOwner(GameInstance), NetManager(nullptr)
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
    if (NetManager->getID() != Net::ID::SERVER)
    {
        CGameBuffer DataBuffer;
        DataBuffer.write(packet->getData());
        DataBuffer.reset();

        Net::NetMessageType MessageType;
        DataBuffer.read(MessageType);
        switch (MessageType)
        {
        case Net::NetMessageType::START_GAME:
            {
                char Level[64];
                DataBuffer.read(Level);
                UGameplayStatics::OpenLevel(GameInstanceOwner->GetWorld(), Level);
            }
            break;
        }
    }
}

void CGameNetManager::connectionPacketReceived(Net::CPacket* packet)
{
    if (NetManager->getID() == Net::ID::SERVER)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Client connected"));
    }
}

void CGameNetManager::disconnectionPacketReceived(Net::CPacket* packet) {}
