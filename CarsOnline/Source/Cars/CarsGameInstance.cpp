// Fill out your copyright notice in the Description page of Project Settings.


#include "CarsGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "GameNet/GameBuffer.h"
#include "Kismet/GameplayStatics.h"

void UCarsGameInstance::OnStart()
{
    Super::OnStart();
    ChangeMenuWidget(StartingWidgetClass);
}

UCarsGameInstance::UCarsGameInstance(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
      , GameNetManager(this)
      , NetManager(nullptr)
{
    NetManager = Net::CManager::getSingletonPtr();
}

void UCarsGameInstance::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
    if (CurrentWidget != nullptr)
    {
        CurrentWidget->RemoveFromViewport();
        CurrentWidget = nullptr;
    }
    if (NewWidgetClass != nullptr)
    {
        CurrentWidget = CreateWidget<UUserWidget>(this, NewWidgetClass);
        if (CurrentWidget != nullptr)
        {
            CurrentWidget->AddToViewport();
        }
    }
}

void UCarsGameInstance::OnServerButtonClick(FString sPort)
{
    int port = FCString::Atoi(*sPort);
    NetManager->activateAsServer(port);
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Server initialization successfuly"));
    }
}

void UCarsGameInstance::OnClientButtonClick(FString sIP, FString sPort)
{
    int port = FCString::Atoi(*sPort);
    NetManager->activateAsClient();
    NetManager->connectTo(TCHAR_TO_ANSI(*sIP), port);
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Client initialization successfuly"));
    }
}

void UCarsGameInstance::OnServerStartButtonClick()
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Server starts!!!"));
    }

    // Load game level
    const char* Level = "circuit1";
    UGameplayStatics::OpenLevel(GetWorld(), Level);

    // Make start game notification for the clients
    CGameBuffer DataBuffer;
    DataBuffer.write(Net::NetMessageType::LOAD_MAP);
    DataBuffer.write(Level);

    // Send notification
    NetManager->send(&DataBuffer, true);
}
