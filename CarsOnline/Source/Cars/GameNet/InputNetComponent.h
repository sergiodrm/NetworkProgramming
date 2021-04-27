// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NetComponent.h"
#include "InputNetComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CARS_API UInputNetComponent : public UNetComponent
{
    GENERATED_BODY()

public:

    // Actor component interface


    // Net functionality

    /**
     * @brief Read data from DataBuffer
     * @param DataBuffer 
    */
    virtual void DeserializeData(CGameBuffer& DataBuffer) override;

    FORCEINLINE void SetInput(const FVector2D& MovementInput) { m_vMovementInput = MovementInput; }
    void OnAttack();

protected:
    virtual void SerializeData() override;
    void SpawnBomb();
    void DestroyBomb();


protected:

    FVector2D m_vMovementInput = FVector2D::ZeroVector;
};
