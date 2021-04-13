#include "NetComponent.h"


#include "Game/Car.h"
#include "Game/CarMovementComponent.h"
#include "CarsGameInstance.h"
#include "Net/Manager.h"
#include "DrawDebugHelpers.h"
#include "GameNet/GameBuffer.h"

namespace
{
    const float SnapshotDelay = 0.2f;
}


UNetComponent::UNetComponent()
    : MovementInput(), NetManager(nullptr), SendCommand(true), TimeToNextSnapshot(0.f)
{
    PrimaryComponentTick.bCanEverTick = true;
    NetManager = Net::CManager::getSingletonPtr();
}

void UNetComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UNetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    UCarsGameInstance* GameInstance = Cast<UCarsGameInstance>(GetWorld()->GetGameInstance());
    if (GameInstance)
    {
        if (GameInstance->GetGameNetManager()->GetOwnCar() == Cast<ACar>(GetOwner())
            || NetManager->getID() == Net::ID::SERVER)
        {
            TimeToNextSnapshot -= DeltaTime;
            SerializeData();
        }
        if (NetManager->getID() != Net::ID::SERVER)
        {
            SimulateCarMovement(DeltaTime);
        }
    }
}

void UNetComponent::SerializeData()
{
    CGameBuffer DataBuffer;
    DataBuffer.write(Net::NetMessageType::ENTITY_MSG);
    if (NetManager->getID() == Net::ID::SERVER)
    {
        if (TimeToNextSnapshot <= 0.f)
        {
            UCarsGameInstance* GameInstance = Cast<UCarsGameInstance>(GetWorld()->GetGameInstance());
            ACar* car = Cast<ACar>(GetOwner());
            unsigned int client = GameInstance->GetGameNetManager()->GetCarId(car);
            DataBuffer.write(client);
            DataBuffer.write(GetOwner()->GetActorLocation());
            DataBuffer.write(car->GetCarMovementComponent()->GetVelocityMagnitude());
            NetManager->send(&DataBuffer, false);
            TimeToNextSnapshot += SnapshotDelay;
        }
    }
    else
    {
        if (SendCommand)
        {
            DataBuffer.write(NetManager->getID());
            DataBuffer.write(MovementInput);
            NetManager->send(&DataBuffer, true);
            SendCommand = false;
        }
    }
}

void UNetComponent::SimulateCarMovement(float DeltaTime)
{
    ACar* car = Cast<ACar>(GetOwner());
    car->GetCarMovementComponent()->MoveActor(LastPackageVelocity, DeltaTime);
}

void UNetComponent::DeserializeData(CGameBuffer& buffer)
{
    if (NetManager->getID() == Net::ID::SERVER)
    {
        FVector2D Input;
        buffer.read(Input);
        ACar* ownerCar = Cast<ACar>(GetOwner());
        if (ownerCar)
        {
            ownerCar->GetCarMovementComponent()->SetInput(Input);
        }
    }
    else
    {
        FTransform transform;
        buffer.read(transform);
        GetOwner()->SetActorTransform(transform);
        float speed;
        buffer.read(speed);
        LastPackageVelocity = GetOwner()->GetActorForwardVector() * speed;
    }
}

void UNetComponent::SetInput(const FVector2D& input)
{
    if (input != MovementInput)
    {
        MovementInput = input;
        SendCommand = true;
    }
}
