// Fill out your copyright notice in the Description page of Project Settings.


#include "BombSpawnerComponent.h"
#include "Bomb.h"
#include "Car.h"

UBombSpawnerComponent::UBombSpawnerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

bool UBombSpawnerComponent::TrySpawnBomb()
{
    if (CanSpawnBomb())
    {
        SpawnBomb();
        return true;
    }
    return false;
}

bool UBombSpawnerComponent::CanSpawnBomb() const { return SpawnedBomb == nullptr; }

void UBombSpawnerComponent::SpawnBomb()
{
    FActorSpawnParameters SpawnParameters;
    SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    FVector SpawnPosition = GetOwner()->GetActorLocation();
    SpawnPosition.Z = 0.f;
    FRotator SpawnRotator = GetOwner()->GetActorRotation();
    SpawnedBomb = GetWorld()->SpawnActor<ABomb>(ABomb::StaticClass(), SpawnPosition, SpawnRotator, SpawnParameters);
    if (SpawnedBomb != nullptr)
    {
        SpawnedBomb->SetActorScale3D(FVector(0.5f));

        // Configure bomb
        SpawnedBomb->OwnerCar = Cast<ACar>(GetOwner());
        if (!SpawnedBomb->OwnerCar->GetNetComponent()->IsMyCar())
        {
            SpawnedBomb->SetMaterialColor(FLinearColor::Red, FLinearColor::Red);
        }
        else
            SpawnedBomb->SetMaterialColor(FLinearColor::Green, FLinearColor::Green);
    }
}

void UBombSpawnerComponent::DestroyBomb()
{
    if (SpawnedBomb != nullptr)
    {
        GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.f, FColor::Red, TEXT("Destroying bomb"));

        SpawnedBomb->Destroy();
        SpawnedBomb = nullptr;
    }
}
