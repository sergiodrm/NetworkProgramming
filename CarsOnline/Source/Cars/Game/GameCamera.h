// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "GameCamera.generated.h"

UCLASS()
class CARS_API AGameCamera : public ACameraActor
{
    GENERATED_BODY()
public:
    // Sets default values for this actor's properties
    AGameCamera();
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    void SetTarget();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

protected:

    class ACar* m_target;

    UPROPERTY(EditAnywhere)
    float m_minDistance;
    UPROPERTY(EditAnywhere)
    float m_distanceFromVelocityFactor;
};
