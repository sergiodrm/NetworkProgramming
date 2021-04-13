// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bomb.generated.h"

UCLASS()
class CARS_API ABomb : public AActor
{
    GENERATED_BODY()

    friend class CGameNetMgr;

public:


    // Sets default values for this actor's properties
    ABomb();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    unsigned int GetOwnerID() const { return OwnerID; }

    UFUNCTION()
    void OnActorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                             UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                             const FHitResult& SweepResult);
    UFUNCTION()
    void OnActorEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                           int32 OtherBodyIndex);

    /**
     *  Components
    */

public:

    UPROPERTY(EditAnywhere)
    class USphereComponent* SphereComponent;

    /**
     *  Members
    */
protected:

    unsigned int OwnerID;

    CGameNetMgr* NetManager;
};
