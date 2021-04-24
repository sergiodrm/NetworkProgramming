// Fill out your copyright notice in the Description page of Project Settings.


#include "InputNetComponent.h"
#include "CarsGameInstance.h"
#include "Game/BombComponent.h"
#include "Game/Car.h"
#include "Game/CarMovementComponent.h"

void UInputNetComponent::DeserializeData(CGameBuffer& DataBuffer)
{
    GameNet::EEntityMessageType msgType;
    DataBuffer.read(msgType);
    if (!IsServer())
    {
        // Read msg as client
        switch (msgType)
        {
            case GameNet::SpawnBomb:
                {
                    SpawnBomb();
                }
                break;
            case GameNet::Transform:
                {
                    FTransform tTrans;
                    DataBuffer.read(tTrans);
                    GetOwner()->SetActorTransform(tTrans);
                }
                break;
        }
    }
    else
    {
        // Read msg as server
        switch (msgType)
        {
            case GameNet::SpawnBomb:
                {
                    SpawnBomb();
                    // Resend to all
                    m_pManager->send(&DataBuffer, true);
                }
                break;
            case GameNet::Input:
                {
                    FVector2D vInput;
                    DataBuffer.read(vInput);
                    ACar* pCar = Cast<ACar>(GetOwner());
                    pCar->GetCarMovement()->SetInput(vInput);
                }
                break;
        }
    }
}

void UInputNetComponent::OnAttack()
{
    if (!IsServer() && IsMyCar())
    {
        std::unique_ptr<CGameBuffer> data = CreateEntityMessage(GameNet::SpawnBomb);
        FString str = FString::Printf(TEXT("Sending request: Client(%d)"), m_pManager->getID());
        GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, str);
        m_pManager->send(data.get(), true);
    }
}

void UInputNetComponent::SerializeData()
{
    if (IsServer())
    {
        std::unique_ptr<CGameBuffer> data = CreateEntityMessage(GameNet::EEntityMessageType::Transform);
        data->write(GetOwner()->GetActorTransform());
        m_pManager->send(data.get(), false);
    }
    else
    {
        std::unique_ptr<CGameBuffer> data = CreateEntityMessage(GameNet::EEntityMessageType::Input);
        data->write(m_vMovementInput);
        m_pManager->send(data.get(), false);
    }
}

void UInputNetComponent::SpawnBomb()
{
    OwnerCar->GetBombComponent()->TrySpawnBomb();
}
