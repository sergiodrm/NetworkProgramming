// Fill out your copyright notice in the Description page of Project Settings.


#include "NetComponent.h"
#include "Net/Manager.h"
#include "CarsGameInstance.h"
#include "Game/Car.h"
#include "DrawDebugHelpers.h"
#include "GameNet/GameBuffer.h"
#include "Game/CarMovementComponent.h"

// Sets default values for this component's properties
UNetComponent::UNetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	m_pManager = Net::CManager::getSingletonPtr();
	// ...
}


// Called when the game starts
void UNetComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UNetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UCarsGameInstance* pGameInstance = Cast<UCarsGameInstance>(GetWorld()->GetGameInstance());
	if (pGameInstance)
	{
		if (pGameInstance->GetGameNetMgr()->GetOwnCar() == GetOwner()
			|| m_pManager->getID() == Net::ID::SERVER)
		{
			SerializeData();
		}
	}
}

void UNetComponent::SerializeData()
{
	CGameBuffer oData;
	oData.write(Net::NetMessageType::ENTITY_MSG);
	if (m_pManager->getID() == Net::ID::SERVER)
	{
		UCarsGameInstance* pGameInstance = Cast<UCarsGameInstance>(GetWorld()->GetGameInstance());
		ACar* pCar = Cast<ACar>(GetOwner());
		unsigned int uID = pGameInstance->GetGameNetMgr()->GetCarID(pCar);
		oData.write(uID);
		oData.write(GetOwner()->GetActorTransform());
		m_pManager->send(&oData, false);
	}
	else
	{
		oData.write(m_pManager->getID());
		oData.write(m_vMovementInput);
		m_pManager->send(&oData, false);
	}
}

void UNetComponent::DeserializeData(CGameBuffer& _rData)
{
	if (m_pManager->getID() != Net::ID::SERVER)
	{
		FTransform tTrans;
		_rData.read(tTrans);
		GetOwner()->SetActorTransform(tTrans);
	}
	else
	{
		FVector2D vInput;
		_rData.read(vInput);
		ACar* pCar = Cast<ACar>(GetOwner());
		pCar->GetCarMovement()->SetInput(vInput);
	}
}