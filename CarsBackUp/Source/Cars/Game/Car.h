// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Car.generated.h"

class UCarMovementComponent;
class UNetComponent;

UCLASS()
class CARS_API ACar : public APawn
{
  GENERATED_BODY()

public:
  // Sets default values for this pawn's properties
  ACar();
  // Called every frame
  virtual void Tick(float DeltaTime) override;
  // Called to bind functionality to input
  virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
  //
  float GetVelocityMagnitude() const;

  void SetInput(const FVector2D& _vInput) { m_vMovementInput = _vInput; }

  UNetComponent* GetNetComponent() { return m_pNet; }
  UCarMovementComponent* GetCarMovement() { return m_pCarMovement; }

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;
  //Input functions
  void Move(float AxisValue);
  void Turn(float AxisValue);

protected:
  //Mesh
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* m_pMesh;
	//Movement
	UPROPERTY(EditAnywhere)
		UCarMovementComponent* m_pCarMovement;
	//Net
	UPROPERTY(EditAnywhere)
		UNetComponent* m_pNet;
  //Input variables
  FVector2D m_vMovementInput = FVector2D::ZeroVector;
};
