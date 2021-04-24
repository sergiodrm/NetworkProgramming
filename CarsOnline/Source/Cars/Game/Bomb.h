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

    UFUNCTION()
    void OnActorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                             UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                             const FHitResult& SweepResult);
    UFUNCTION()
    void OnActorEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                           int32 OtherBodyIndex);

    virtual void Tick(float DeltaSeconds) override;

public:

    ACar* OwnerCar;

    UPROPERTY(VisibleAnywhere)
    class USphereComponent* SphereComponent;
    UPROPERTY(VisibleAnywhere)
    class USlowDownNetComponent* SlowDownNetComponent;
    UPROPERTY(VisibleAnywhere)
    class UStaticMeshComponent* StaticMeshComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bomb settings")
    float m_fEffectRadius;
};
