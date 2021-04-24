// Fill out your copyright notice in the Description page of Project Settings.


#include "GameNetMgr.h"
#include "GameNet/GameBuffer.h"
#include "Net/packet.h"
#include "Kismet/GameplayStatics.h"
#include "CarsGameInstance.h"
#include "InputNetComponent.h"
#include "Engine/World.h"
#include "Engine/LevelStreaming.h"
#include "Game/Car.h"
#include "GameNet/NetComponent.h"

CGameNetMgr::CGameNetMgr()
{
    Net::CManager::Init();
    m_pManager = Net::CManager::getSingletonPtr();
    m_pManager->addObserver(this);
}

CGameNetMgr::CGameNetMgr(UCarsGameInstance* _pOwner)
    : m_pCarsGameInstance(_pOwner)
{
    Net::CManager::Init();
    m_pManager = Net::CManager::getSingletonPtr();
    m_pManager->addObserver(this);
}

CGameNetMgr::~CGameNetMgr()
{
    m_pManager->removeObserver(this);
    Net::CManager::Release();
}

void CGameNetMgr::dataPacketReceived(Net::CPacket* packet)
{
    CGameBuffer oData;
    oData.write(packet->getData(), packet->getDataLength());
    oData.reset();
    Net::NetMessageType xType;
    oData.read(xType);
    switch (xType)
    {
        case Net::NetMessageType::LOAD_MAP:
            {
                char sLevel[64];
                oData.read(sLevel);
                UGameplayStatics::OpenLevel(m_pCarsGameInstance->GetWorld(), sLevel);
                CGameBuffer oData2;
                oData2.write(Net::NetMessageType::MAP_LOADED);
                m_pManager->send(&oData2, true);
            }
            break;
        case Net::NetMessageType::MAP_LOADED:
            {
                ++m_uMapLoadedNotifications;
                if (m_uMapLoadedNotifications >= m_pManager->getConnections().size())
                {
                    for (auto client : m_pManager->getConnections())
                    {
                        CGameBuffer oData2;
                        oData2.write(Net::NetMessageType::LOAD_PLAYER);
                        oData2.write(client.first);
                        FVector vPos(220.f, -310.f + 40.f * client.first, 0.f);
                        oData2.write(vPos);
                        CreateCar(client.first, vPos);
                        m_pManager->send(&oData2, true);
                    }
                }
            }
            break;
        case Net::NetMessageType::LOAD_PLAYER:
            {
                unsigned int uClient;
                oData.read(uClient);
                FVector vPos;
                oData.read(vPos);
                CreateCar(uClient, vPos);
                if (uClient == m_pManager->getID())
                {
                    APlayerController* OurPC = GEngine->GetFirstLocalPlayerController(m_pCarsGameInstance->GetWorld());
                    if (OurPC)
                    {
                        OurPC->Possess(m_vPlayers[uClient]);
                    }
                }
            }
            break;
        case Net::NetMessageType::ENTITY_MSG:
            {
                unsigned int uClient;
                oData.read(uClient);
                ACar* pCar = m_vPlayers.at(uClient);
                pCar->GetNetComponent()->DeserializeData(oData);
            }
            break;
    }
}

void CGameNetMgr::CreateCar(unsigned int _iClient, FVector _vPos)
{
    FActorSpawnParameters SpawnInfo;
    SpawnInfo.Name = FName("Car", _iClient);
    SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    ACar* pCar = m_pCarsGameInstance->GetWorld()->SpawnActor<ACar>(_vPos, FRotator::ZeroRotator, SpawnInfo);
    if (pCar)
    {
        m_vPlayers[_iClient] = pCar;
        m_vPlayerIDs[pCar] = _iClient;
    }
}

ACar* CGameNetMgr::GetOwnCar() const
{
    if (m_pManager->getID() != Net::ID::SERVER)
    {
        return m_vPlayers.at(m_pManager->getID());
    }
    return nullptr;
}

unsigned int CGameNetMgr::GetCarID(ACar* _pCar) const
{
    return m_vPlayerIDs.at(_pCar);
}

void CGameNetMgr::connectionPacketReceived(Net::CPacket* packet)
{
    if (m_pManager->getID() == Net::ID::SERVER)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, *FString("Client connected!"));
    }
}

void CGameNetMgr::disconnectionPacketReceived(Net::CPacket* packet)
{}
