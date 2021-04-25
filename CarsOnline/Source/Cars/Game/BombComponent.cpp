// Fill out your copyright notice in the Description page of Project Settings.


#include "BombComponent.h"
#include "Bomb.h"
#include "Car.h"

UBombComponent::UBombComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

bool UBombComponent::TrySpawnBomb()
{
    if (CanSpawnBomb())
    {
        SpawnBomb();
        return true;
    }
    return false;
}

bool UBombComponent::CanSpawnBomb() const { return SpawnedBomb == nullptr; }

void UBombComponent::SpawnBomb()
{
    FActorSpawnParameters SpawnParameters;
    SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    FVector position = GetOwner()->GetActorLocation();
    FRotator rotator = GetOwner()->GetActorRotation();
    FVector scale = GetOwner()->GetActorScale();
    SpawnedBomb = GetWorld()->SpawnActor<ABomb>(ABomb::StaticClass(), position, rotator, SpawnParameters);
    if (SpawnedBomb != nullptr)
    {
        SpawnedBomb->SetActorScale3D(FVector(0.5f));

        // Configure bomb
        SpawnedBomb->OwnerCar = Cast<ACar>(GetOwner());
        if (!SpawnedBomb->OwnerCar->GetNetComponent()->IsMyCar())
        {
            SpawnedBomb->SetMaterialColor(FLinearColor::Red);
        }
    }
}

void UBombComponent::DestroyBomb()
{
    if (SpawnedBomb != nullptr)
    {
        GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.f, FColor::Red, TEXT("Destroying bomb"));

        SpawnedBomb->Destroy();
        SpawnedBomb = nullptr;
    }
}
