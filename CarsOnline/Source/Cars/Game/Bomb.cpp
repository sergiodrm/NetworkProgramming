// Fill out your copyright notice in the Description page of Project Settings.

#include "Bomb.h"

#include "Components/SphereComponent.h"
#include "GameNet/SlowDownNetComponent.h"
#include "Game/Car.h"

ABomb::ABomb()
{
    PrimaryActorTick.bCanEverTick = true;

    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere component"));
    RootComponent = SphereComponent;
    SphereComponent->InitSphereRadius(m_fEffectRadius);
    SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ABomb::OnActorBeginOverlap);
    SphereComponent->OnComponentEndOverlap.AddDynamic(this, &ABomb::OnActorEndOverlap);

    SlowDownNetComponent = CreateDefaultSubobject<USlowDownNetComponent>(TEXT("Slow down net component"));

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static mesh component"));
    const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
    StaticMeshComponent->SetStaticMesh(MeshObj.Object);
}

void ABomb::OnActorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                const FHitResult& SweepResult)
{
    ACar* OverlappingCar = Cast<ACar>(OtherActor);
    if (OverlappingCar && OverlappingCar != OwnerCar)
    {
        SlowDownNetComponent->AddCarBeginOverlap(OverlappingCar);
    }
}

void ABomb::OnActorEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                              UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {}

void ABomb::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}
