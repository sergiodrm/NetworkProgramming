// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NetComponent.h"
#include "SlowDownNetComponent.generated.h"


class ACar;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CARS_API USlowDownNetComponent : public UNetComponent
{
    GENERATED_BODY()

public:

    // Net functionality

    virtual void DeserializeData(CGameBuffer& DataBuffer) override;
protected:
    virtual void SerializeData() override;

public:
    // Own logic

    void AddCarBeginOverlap(ACar* Car);
    void AddCarEndOverlap(ACar* Car);

    // Own members

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slow down settings")
    float m_fSlowDownFactor {0.5f};

private:

    TArray<ACar*> CarsBeginOverlap;
    TArray<ACar*> CarsEndOverlap;
};
