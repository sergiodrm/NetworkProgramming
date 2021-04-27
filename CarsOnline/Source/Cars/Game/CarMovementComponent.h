// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CarMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CARS_API UCarMovementComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UCarMovementComponent();

    float GetVelocityMagnitude() { return m_vVelocity.Size(); }
    void SetInput(FVector2D _vInput) { m_vMovementInput = _vInput; }

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType,
                               FActorComponentTickFunction* ThisTickFunction) override;
    FVector CalculateAcceleration() const;
    FVector CalculateAverageVelocity(const FVector& _vAccel, float DeltaTime);
    void ClampVelocity(FVector& _vVelocity) const;
    void MoveActor(const FVector& _vVelocity, float DeltaTime);
    void SlowDownVelocity(float _slowDownFactor);
    void RestoreVelocity();
    float GetMaxVelocity() const { return m_fMaxVelocityBackUp; }

protected:
    UPROPERTY(EditAnywhere)
    float m_fAccel = 120.f;
    UPROPERTY(EditAnywhere)
    float m_fDrag = 50.f;
    UPROPERTY(EditAnywhere)
    float m_fBrake = 300.f;
    UPROPERTY(EditAnywhere)
    float m_fRotationFactor = 2.f;
    UPROPERTY(EditAnywhere)
    float m_fMaxVelocity = 250.f;
    float m_fMaxVelocityBackUp = 250.f;
    //
    FVector m_vVelocity = FVector::ZeroVector;
    //
    FVector2D m_vMovementInput = FVector2D::ZeroVector;
};
