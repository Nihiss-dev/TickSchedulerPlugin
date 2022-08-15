// Fill out your copyright notice in the Description page of Project Settings.


#include "TickSchedulerSubsystem.h"
#include "TickSchedulerInterface.h"

void UTickSchedulerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	m_TickHandle = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UTickSchedulerSubsystem::Update));
}

void UTickSchedulerSubsystem::Deinitialize()
{
	FTicker::GetCoreTicker().RemoveTicker(m_TickHandle);
	Super::Deinitialize();
}

void UTickSchedulerSubsystem::RegisterInterface(ITickSchedulerInterface* toRegister)
{
	toRegister->GetActor()->SetActorTickEnabled(false);
	m_Queue.RegisterInterface(toRegister);
}

void UTickSchedulerSubsystem::UnregisterInterface(ITickSchedulerInterface* toUnregister, bool reactivateTick /* = false*/)
{
	m_Queue.UnregisterInterface(toUnregister);
	toUnregister->GetActor()->SetActorTickEnabled(reactivateTick);
}

void UTickSchedulerSubsystem::RegisterPlayer(AActor* Player)
{
	m_Queue.RegisterPlayer(Player);
}

bool UTickSchedulerSubsystem::Update(float DeltaTime)
{
	m_Queue.Update(DeltaTime);
	return true;
}