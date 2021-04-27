// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/CarUserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UCarUserWidget::UpdateVelocity(float currentVelocity)
{
    const FString str(FString::Printf(TEXT("Velocity: %.2f u/s"), currentVelocity));
    VelocityText->SetText(FText::FromString(str));
}
