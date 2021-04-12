// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Net/Manager.h"


class UCarsGameInstance;
/**
 * 
 */
class CGameNetManager : public Net::CManager::IObserver
{
public:
    CGameNetManager(UCarsGameInstance* GameInstance = nullptr);
    virtual ~CGameNetManager();

    virtual void dataPacketReceived(Net::CPacket* packet) override;
    virtual void connectionPacketReceived(Net::CPacket* packet) override;
    virtual void disconnectionPacketReceived(Net::CPacket* packet) override;

private:

    UCarsGameInstance* GameInstanceOwner;

    Net::CManager* NetManager;
};
