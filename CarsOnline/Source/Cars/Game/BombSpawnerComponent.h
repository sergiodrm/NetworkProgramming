// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BombSpawnerComponent.generated.h"


class ABomb;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CARS_API UBombSpawnerComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UBombSpawnerComponent();

    bool TrySpawnBomb();
    bool CanSpawnBomb() const;
    void DestroyBomb();

protected:
    void SpawnBomb();

public:
    ABomb* SpawnedBomb;
};
