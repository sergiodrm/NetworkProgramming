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

protected:
  // Called when the game starts
  virtual void BeginPlay() override;

public:


  // Called every frame
  virtual void TickComponent(float DeltaTime, ELevelTick TickType,
                             FActorComponentTickFunction* ThisTickFunction) override;

  void SetInput(const FVector2D& _input) { m_movementInput = _input; }
  float GetVelocityMagnitude() const { return m_velocity.Size(); }
  FVector CalculateAcceleration() const;
  FVector CalculateAverageVelocity(const FVector& _acceleration, float _deltaTime);
  void ClampVelocity(FVector& _velocity_) const;
  void MoveActor(const FVector _averageVelocity, float _deltaTime);

protected:

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float m_acceleration;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float m_rotationFactor;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float m_brake;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float m_drag;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float m_maxVelocity;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FVector2D m_movementInput;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FVector m_velocity;
};
