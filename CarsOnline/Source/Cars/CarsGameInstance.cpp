// Fill out your copyright notice in the Description page of Project Settings.


#include "CarsGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "Net/Manager.h"
#include "GameNet/GameBuffer.h"
#include "Kismet/GameplayStatics.h"

UCarsGameInstance::UCarsGameInstance(const FObjectInitializer& OI)
	: Super(OI)
	, m_oGameNetMgr(this)
{
	m_pManager = Net::CManager::getSingletonPtr();
}

void UCarsGameInstance::OnStart()
{
  Super::OnStart();
  ChangeMenuWidget(StartingWidgetClass);
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
	int iPort(FCString::Atoi(*sPort));
	m_pManager->activateAsServer(iPort);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, *FString("Server"));
}

void UCarsGameInstance::OnClientButtonClick(FString sIP, FString sPort)
{
	int iPort(FCString::Atoi(*sPort));
	m_pManager->activateAsClient();
	m_pManager->connectTo(TCHAR_TO_ANSI(*sIP), iPort);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, *FString("Client"));
}

void UCarsGameInstance::OnServerStartButtonClick()
{
	const char* level = "circuit1";
	UGameplayStatics::OpenLevel(GetWorld(), level);
	CGameBuffer oData;
	oData.write(Net::NetMessageType::LOAD_MAP);
	oData.write(level);
	m_pManager->send(&oData, true);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, *FString("Server Start!"));
}
