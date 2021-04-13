// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NetComponent.generated.h"


class CGameBuffer;

namespace Net
{
    class CManager;
}

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNetComponent : public UActorComponent
{
    GENERATED_BODY()
public:

    UNetComponent();


protected:

    virtual void BeginPlay() override;

public:

    virtual void TickComponent(float DeltaTime, ELevelTick TickType,
                               FActorComponentTickFunction* ThisTickFunction) override;

    void DeserializeData(CGameBuffer& buffer);

    void SetInput(const FVector2D& input);

protected:

    void SerializeData();
    void SimulateCarMovement(float DeltaTime);

protected:

    FVector2D MovementInput;
    Net::CManager* NetManager;
    bool SendCommand;
    float TimeToNextSnapshot;
    FVector LastPackageVelocity;
};
