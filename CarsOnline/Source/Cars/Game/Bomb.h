// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bomb.generated.h"

class ACar;
class UCarMovementComponent;
class UNetComponent;

UCLASS()
class CARS_API ABomb : public AActor
{
    GENERATED_BODY()

public:

    ABomb();

    virtual void Tick(float DeltaSeconds) override;

    void SetMaterialColor(const FLinearColor& BaseColor, const FLinearColor& EmissiveColor);
    void OnDestroy();

public:

    ACar* OwnerCar;

    UPROPERTY(VisibleAnywhere)
    class USceneComponent* SceneComponent;
    UPROPERTY(VisibleAnywhere)
    class UStaticMeshComponent* StaticMeshComponent;
    UPROPERTY(VisibleAnywhere)
    class UNetComponent* m_pNetComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bomb settings")
    float m_fEffectRadius;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bomb settings")
    float m_fSlowDownFactor;

    UPROPERTY(VisibleAnywhere)
    class UDecalComponent* DecalComponent;

protected:
    TArray<ACar*> AffectedCars;
};
