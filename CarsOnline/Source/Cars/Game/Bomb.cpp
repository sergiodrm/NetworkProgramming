// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/Bomb.h"


#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ABomb::ABomb()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
    RootComponent = SphereComponent;

    SphereComponent->InitSphereRadius(200.f);

    SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ABomb::OnActorBeginOverlap);
    SphereComponent->OnComponentEndOverlap.AddDynamic(this, &ABomb::OnActorEndOverlap);
}

// Called when the game starts or when spawned
void ABomb::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ABomb::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ABomb::OnActorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                const FHitResult& SweepResult)
{ }

void ABomb::OnActorEndOverlap(UPrimitiveComponent* OverlappedComponent,
                              AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{ }
