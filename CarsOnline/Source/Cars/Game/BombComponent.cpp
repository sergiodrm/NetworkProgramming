// Fill out your copyright notice in the Description page of Project Settings.


#include "BombComponent.h"
#include "Bomb.h"

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
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, TEXT("Spawning bomb"));
    }
}
