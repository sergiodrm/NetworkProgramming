// Fill out your copyright notice in the Description page of Project Settings.


#include "CarMovementComponent.h"

// Sets default values for this component's properties
UCarMovementComponent::UCarMovementComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;

    // ...
}


// Called when the game starts
void UCarMovementComponent::BeginPlay()
{
    Super::BeginPlay();

    // ...
}

FVector UCarMovementComponent::CalculateAcceleration() const
{
    FVector vAccel;
    if (m_vMovementInput.Y > 0.f)
    {
        vAccel = m_fAccel * m_vMovementInput.Y * GetOwner()->GetActorForwardVector();
    }
    else if (m_vMovementInput.Y < 0.f)
    {
        vAccel = m_fBrake * m_vMovementInput.Y * GetOwner()->GetActorForwardVector();
    }
    else //if (m_vMovementInput.Y == 0.f)
    {
        vAccel = -m_fDrag * GetOwner()->GetActorForwardVector();
    }

    vAccel += m_vMovementInput.X * m_vVelocity.Size() * m_fRotationFactor * GetOwner()->GetActorRightVector();

    return vAccel;
}

FVector UCarMovementComponent::CalculateAverageVelocity(const FVector& _vAccel, float DeltaTime)
{
    FVector vAverageVelocity = m_vVelocity + 0.5f * _vAccel * DeltaTime;
    ClampVelocity(vAverageVelocity);

    // Update the Velocity for the next step
    m_vVelocity += _vAccel * DeltaTime;
    ClampVelocity(m_vVelocity);
    return vAverageVelocity;
}

void UCarMovementComponent::ClampVelocity(FVector& _vVelocity) const
{
    if (_vVelocity != FVector::ZeroVector && FVector::DotProduct(_vVelocity, GetOwner()->GetActorForwardVector()) < 0.f)
    {
        _vVelocity = FVector::ZeroVector;
    }

    float fSizeSquared = _vVelocity.SizeSquared();
    if (fSizeSquared > m_fMaxVelocity * m_fMaxVelocity)
    {
        float fSize = _vVelocity.Size();
        _vVelocity *= m_fMaxVelocity / fSize;
    }
}

void UCarMovementComponent::MoveActor(const FVector& _vAverageVelocity, float DeltaTime)
{
    auto oTrans = GetOwner()->GetActorTransform();
    oTrans.AddToTranslation(_vAverageVelocity * DeltaTime);
    GetOwner()->SetActorTransform(oTrans);

    if (_vAverageVelocity != FVector::ZeroVector)
    {
        FRotator Rot = FRotationMatrix::MakeFromX(_vAverageVelocity).Rotator();
        GetOwner()->SetActorRotation(Rot);
    }
}

void UCarMovementComponent::SlowDownVelocity(float _slowDownFactor)
{
    m_fMaxVelocity *= _slowDownFactor;
}

void UCarMovementComponent::RestoreVelocity()
{
    m_fMaxVelocity = m_fMaxVelocityBackUp;
}


// Called every frame
void UCarMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    FVector vAccel = CalculateAcceleration();
    FVector vAverageVelocity = CalculateAverageVelocity(vAccel, DeltaTime);
    MoveActor(vAverageVelocity, DeltaTime);
}
