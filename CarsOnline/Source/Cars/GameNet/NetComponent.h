// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <memory>


#include "GameNetMgr.h"
#include "Components/ActorComponent.h"
#include "GameNet/GameBuffer.h"
#include "NetComponent.generated.h"

class ACar;

namespace Net
{
    class CManager;
}

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CARS_API UNetComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UNetComponent();

    // --- Actor component interface ---

    /**
     * @brief Called every frame
    */
    virtual void TickComponent(float DeltaTime, ELevelTick TickType,
                               FActorComponentTickFunction* ThisTickFunction) override;

    // --- Net functionality ---

    bool IsMyCar() const;
    bool IsServer() const;
    virtual void DeserializeData(CGameBuffer& DataBuffer);

protected:

    virtual void SerializeData();
    std::unique_ptr<CGameBuffer> CreateEntityMessage(GameNet::EEntityMessageType type) const;


protected:
    Net::CManager* m_pManager = nullptr;
    class ACar* OwnerCar;
};
