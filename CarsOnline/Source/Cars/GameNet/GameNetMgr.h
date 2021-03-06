// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <memory>

#include "GameBuffer.h"
#include "Net/Manager.h"

class UCarsGameInstance;
class ACar;

namespace GameNet
{
    enum EEntityMessageType : int
    {
        None = -1,
        Transform,
        Input,
        SpawnBomb,
        DestroyBomb,
        Effect
    };
}

/**
 * 
 */
class CGameNetMgr : public Net::CManager::IObserver
{
public:
    CGameNetMgr();
    CGameNetMgr(UCarsGameInstance* _pOwner);
    virtual ~CGameNetMgr();
public:
    virtual void dataPacketReceived(Net::CPacket* packet) override;
    virtual void connectionPacketReceived(Net::CPacket* packet) override;
    virtual void disconnectionPacketReceived(Net::CPacket* packet) override;

    void CreateCar(unsigned int _iClient, FVector _vPos);
    ACar* GetOwnCar() const;
    unsigned int GetCarID(ACar* _pCar) const;

private:
    UCarsGameInstance* m_pCarsGameInstance = nullptr;
    Net::CManager* m_pManager = nullptr;
    unsigned int m_uMapLoadedNotifications = 0u;
    std::map<unsigned int, ACar*> m_vPlayers;
    std::map<ACar*, unsigned int> m_vPlayerIDs;
};
