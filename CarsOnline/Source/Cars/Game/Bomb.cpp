// Fill out your copyright notice in the Description page of Project Settings.

#include "Bomb.h"

#include "Components/SphereComponent.h"
#include "GameNet/SlowDownNetComponent.h"
#include "Game/Car.h"
#include "Components/StaticMeshComponent.h"

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
    StaticMeshComponent->SetupAttachment(RootComponent);
    const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
    StaticMeshComponent->SetStaticMesh(MeshObj.Object);
    const ConstructorHelpers::FObjectFinder<UMaterial> MaterialObj(TEXT("Material'/Game/BombMaterial.BombMaterial'"));
    StaticMeshComponent->SetMaterial(0, MaterialObj.Object);

    StaticMeshComponent->SetRelativeLocation(FVector::ZeroVector);
    StaticMeshComponent->SetRelativeScale3D(FVector(0.3f));
    StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    StaticMeshComponent->SetCollisionProfileName("NoCollision");
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

void ABomb::SetMaterialColor(const FLinearColor& color)
{
    UMaterialInstanceDynamic* MaterialInstance = StaticMeshComponent->CreateAndSetMaterialInstanceDynamic(0);
    MaterialInstance->SetVectorParameterValue(FName(TEXT("BaseColor")), color);
}
