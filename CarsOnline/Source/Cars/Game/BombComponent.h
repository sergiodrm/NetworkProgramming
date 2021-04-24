// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BombComponent.generated.h"


class ABomb;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CARS_API UBombComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UBombComponent();

    bool TrySpawnBomb();
    bool CanSpawnBomb() const;

protected:
    void SpawnBomb();

public:

    ABomb* SpawnedBomb;
};
