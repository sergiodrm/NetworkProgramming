// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/CarMovementComponent.h"

// Sets default values for this component's properties
UCarMovementComponent::UCarMovementComponent()
{
  // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
  // off to improve performance if you don't need them.
  PrimaryComponentTick.bCanEverTick = true;

  m_acceleration = 120.f;
  m_drag = 50.f;
  m_brake = 300.f;
  m_rotationFactor = 2.f;
  m_maxVelocity = 250.f;
  m_movementInput = FVector2D::ZeroVector;
  m_velocity = FVector::ZeroVector;
}


// Called when the game starts
void UCarMovementComponent::BeginPlay()
{
  Super::BeginPlay();

  // ...
}


// Called every frame
void UCarMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  FVector acceleration = CalculateAcceleration();
  FVector averageVelocity = CalculateAverageVelocity(acceleration, DeltaTime);
  MoveActor(averageVelocity, DeltaTime);
}

FVector UCarMovementComponent::CalculateAcceleration() const
{
  FVector accel;
  if (m_movementInput.Y > 0.f)
  {
    accel = m_acceleration * m_movementInput.Y * GetOwner()->GetActorForwardVector();
  }
  else if (m_movementInput.Y < 0.f)
  {
    accel = m_brake * m_movementInput.Y * GetOwner()->GetActorForwardVector();
  }
  else
  {
    accel = -m_drag * GetOwner()->GetActorForwardVector();
  }

  accel += m_movementInput.X * m_velocity.Size() * m_rotationFactor * GetOwner()->GetActorRightVector();
  return accel;
}

FVector UCarMovementComponent::CalculateAverageVelocity(const FVector& _acceleration, float _deltaTime)
{
  FVector averageVelocity = m_velocity + 0.5f * _acceleration * _deltaTime;
  ClampVelocity(averageVelocity);
  // Update velocity for next step
  m_velocity += _acceleration * _deltaTime;
  ClampVelocity(m_velocity);
  return averageVelocity;
}

void UCarMovementComponent::ClampVelocity(FVector& _velocity_) const
{
  if (_velocity_ != FVector::ZeroVector && FVector::DotProduct(_velocity_, GetOwner()->GetActorForwardVector()) < 0.f)
  {
    _velocity_ = FVector::ZeroVector;
  }

  float sizeSquared = _velocity_.SizeSquared();
  if (sizeSquared > m_maxVelocity * m_maxVelocity)
  {
    _velocity_ *= m_maxVelocity / _velocity_.Size();
  }
}

void UCarMovementComponent::MoveActor(const FVector _averageVelocity, float _deltaTime)
{
  FTransform transform = GetOwner()->GetActorTransform();
  transform.AddToTranslation(_averageVelocity * _deltaTime);
  GetOwner()->SetActorTransform(transform);
  if (_averageVelocity != FVector::ZeroVector)
  {
    FRotator rotation = FRotationMatrix::MakeFromX(_averageVelocity).Rotator();
    GetOwner()->SetActorRotation(rotation);
  }
}
