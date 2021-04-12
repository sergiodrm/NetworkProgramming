// Fill out your copyright notice in the Description page of Project Settings.

#include "CarsGameModeBase.h"
#include "Game/CarsPlayerController.h"
#include "Net/Manager.h"

ACarsGameModeBase::ACarsGameModeBase(const class FObjectInitializer& ObjectInitializer) : AGameModeBase(
    ObjectInitializer)
{
    PlayerControllerClass = ACarsPlayerController::StaticClass();

    PrimaryActorTick.bCanEverTick = true;
}

APawn* ACarsGameModeBase::SpawnDefaultPawnFor_Implementation(AController* NewPlayer, AActor* StartSpot)
{
    return nullptr;
}

void ACarsGameModeBase::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    Net::CManager* NetManager = Net::CManager::getSingletonPtr();
    if (NetManager)
    {
        NetManager->tick();
    }
}
