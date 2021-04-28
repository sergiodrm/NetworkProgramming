// Fill out your copyright notice in the Description page of Project Settings.

#include "Bomb.h"


#include "CarMovementComponent.h"
#include "DrawDebugHelpers.h"
#include "Components/DecalComponent.h"
#include "Components/SphereComponent.h"
#include "Game/Car.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

ABomb::ABomb()
{
    PrimaryActorTick.bCanEverTick = true;
    m_fSlowDownFactor = 0.5f;
    m_fEffectRadius = 200.f;

    SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene component"));
    RootComponent = SceneComponent;
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

    DecalComponent = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal component"));
    DecalComponent->SetupAttachment(RootComponent);
    DecalComponent->DecalSize = FVector(m_fEffectRadius * 2.f, m_fEffectRadius * 2.f, m_fEffectRadius * 2.f);
    DecalComponent->FadeDuration = 0.f;
    DecalComponent->AddLocalRotation(FRotator(90.f, 0.f, 0.f));

    const ConstructorHelpers::FObjectFinder<UMaterial> DecalMaterialObj(
        TEXT("Material'/Game/BombDecalMaterial.BombDecalMaterial'"));
    DecalComponent->SetMaterial(0, DecalMaterialObj.Object);

    m_pNetComponent = CreateDefaultSubobject<UNetComponent>(TEXT("Net component"));
}

void ABomb::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    // Slow down logic
    if (m_pNetComponent->IsServer())
    {
        TArray<AActor*> CarActors;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACar::StaticClass(), CarActors);
        for (AActor* Actor : CarActors)
        {
            ACar* Car = Cast<ACar>(Actor);
            if (Car != OwnerCar)
            {
                float squareDistance = (Car->GetActorLocation() - GetActorLocation()).SizeSquared();
                if (AffectedCars.Find(Car) != INDEX_NONE)
                {
                    if (squareDistance > m_fEffectRadius * m_fEffectRadius)
                    {
                        Car->GetCarMovement()->RestoreVelocity();
                        AffectedCars.Remove(Car);
                    }
                }
                else
                {
                    if (squareDistance <= m_fEffectRadius * m_fEffectRadius)
                    {
                        Car->GetCarMovement()->SlowDownVelocity(m_fSlowDownFactor);
                        AffectedCars.Add(Car);
                    }
                }
            }
        }
    }
}

void ABomb::SetMaterialColor(const FLinearColor& BaseColor, const FLinearColor& EmissiveColor)
{
    UMaterialInstanceDynamic* BombMaterialInstance = StaticMeshComponent->CreateAndSetMaterialInstanceDynamic(0);
    BombMaterialInstance->SetVectorParameterValue(TEXT("BaseColor"), BaseColor);
    BombMaterialInstance->SetVectorParameterValue(TEXT("EmissiveColor"), EmissiveColor);

    UMaterialInstanceDynamic* DecalMaterialInstance = UMaterialInstanceDynamic::Create(
        DecalComponent->GetMaterial(0), this);
    DecalMaterialInstance->SetVectorParameterValue(TEXT("BaseColor"), BaseColor);
    DecalComponent->SetMaterial(0, DecalMaterialInstance);
}

void ABomb::OnDestroy()
{
    if (m_pNetComponent->IsServer())
    {
        // We have to restore all cars velocity
        for (ACar* car : AffectedCars)
        {
            car->GetCarMovement()->RestoreVelocity();
        }
    }
}
