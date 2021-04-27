// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CarUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class CARS_API UCarUserWidget : public UUserWidget
{
    GENERATED_BODY()


public:
    void UpdateVelocity(float currentVelocity);

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* VelocityText;
};
