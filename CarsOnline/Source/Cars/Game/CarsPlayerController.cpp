// Fill out your copyright notice in the Description page of Project Settings.

#include "CarsPlayerController.h"

#include "CarUserWidget.h"


ACarsPlayerController::ACarsPlayerController(const class FObjectInitializer& ObjectInitializer) : Super(
    ObjectInitializer)
{
    bAutoManageActiveCameraTarget = false;
    UIWidget = nullptr;
}

void ACarsPlayerController::BeginPlay()
{
    Super::BeginPlay();
    SetInputMode(FInputModeGameAndUI());
    bShowMouseCursor = true;

    UIWidget = CreateWidget<UCarUserWidget>(this, UIWidgetClass.Get());
    if (UIWidget)
    {
        UIWidget->AddToViewport();
    }
}
