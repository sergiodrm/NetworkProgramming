// Fill out your copyright notice in the Description page of Project Settings.


#include "SlowDownNetComponent.h"

#include "Game/Bomb.h"
#include "Game/Car.h"
#include "Game/CarMovementComponent.h"
#include "Net/Manager.h"

void USlowDownNetComponent::DeserializeData(CGameBuffer& DataBuffer)
{ }

void USlowDownNetComponent::SerializeData()
{
    if (IsServer())
    {
        CGameBuffer DataBuffer;
        DataBuffer.write(Net::NetMessageType::ENTITY_MSG);

        // First write the number of cars in CarsBeginOverlap
        DataBuffer.write(CarsBeginOverlap.Num());
        // Serialize cars which began to overlap
        if (CarsBeginOverlap.Num() > 0)
        { }
    }
}

void USlowDownNetComponent::AddCarBeginOverlap(ACar* Car)
{
    if (IsServer())
    {
        CarsBeginOverlap.Add(Car);
        Car->GetCarMovement()->SlowDownVelocity(m_fSlowDownFactor);
    }
}

void USlowDownNetComponent::AddCarEndOverlap(ACar* Car)
{
    if (IsServer())
    {
        CarsEndOverlap.Add(Car);
        Car->GetCarMovement()->RestoreVelocity();
    }
}
