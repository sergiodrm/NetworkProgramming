// Fill out your copyright notice in the Description page of Project Settings.


#include "NetComponent.h"
#include "Net/Manager.h"
#include "CarsGameInstance.h"
#include "Game/Car.h"
#include "DrawDebugHelpers.h"
#include "GameNet/GameBuffer.h"
#include "Game/CarMovementComponent.h"

// Sets default values for this component's properties
UNetComponent::UNetComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;
    m_pManager = Net::CManager::getSingletonPtr();
    OwnerCar = Cast<ACar>(GetOwner());
    // ...
}

// Called every frame
void UNetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (IsMyCar() || IsServer())
    {
        SerializeData();
    }
}

void UNetComponent::BeginPlay()
{
    Super::BeginPlay();

    if (!OwnerCar)
    {
        OwnerCar = Cast<ACar>(GetOwner());
    }
}


bool UNetComponent::IsMyCar() const
{
    UCarsGameInstance* pGameInstance = Cast<UCarsGameInstance>(GetWorld()->GetGameInstance());
    if (pGameInstance)
    {
        return pGameInstance->GetGameNetMgr()->GetOwnCar() == GetOwner();
    }
    UE_LOG(LogTemp, Error, TEXT("Game instance is nullptr!!!"));
    return false;
}

bool UNetComponent::IsServer() const
{
    return m_pManager->getID() == Net::ID::SERVER;
}

void UNetComponent::SerializeData()
{ }

std::unique_ptr<CGameBuffer> UNetComponent::CreateEntityMessage(GameNet::EEntityMessageType type) const
{
    // Get the car id
    Net::NetID id;
    if (IsServer())
    {
        UCarsGameInstance* pGameInstance = Cast<UCarsGameInstance>(GetWorld()->GetGameInstance());
        ACar* pCar = Cast<ACar>(GetOwner());
        id = pGameInstance->GetGameNetMgr()->GetCarID(pCar);
    }
    else
    {
        id = m_pManager->getID();
    }

    // Create the message
    std::unique_ptr<CGameBuffer> data = std::make_unique<CGameBuffer>();
    data->write(Net::NetMessageType::ENTITY_MSG);
    data->write(id);
    data->write(type);
    return data;
}

void UNetComponent::DeserializeData(CGameBuffer& DataBuffer)
{}
