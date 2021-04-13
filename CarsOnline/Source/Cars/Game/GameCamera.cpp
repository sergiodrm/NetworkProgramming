// Fill out your copyright notice in the Description page of Project Settings.

#include "GameCamera.h"
#include "Kismet/GameplayStatics.h"
#include "Car.h"

// Sets default values
AGameCamera::AGameCamera()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    m_target = nullptr;

    m_minDistance = 200.f;
    m_distanceFromVelocityFactor = 0.6f;
}

// Called when the game starts or when spawned
void AGameCamera::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AGameCamera::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (m_target)
    {
        FVector position = m_target->GetActorLocation();
        position.Z += m_minDistance + m_distanceFromVelocityFactor * m_target->GetVelocityMagnitude();
        SetActorLocation(position);
    }
    else
    {
        SetTarget();
    }
}

void AGameCamera::SetTarget()
{
    APlayerController* OurPC = UGameplayStatics::GetPlayerController(this, 0);
    if (OurPC)
    {
        OurPC->SetViewTarget(this);
        m_target = Cast<ACar>(OurPC->GetPawn());
    }
}
