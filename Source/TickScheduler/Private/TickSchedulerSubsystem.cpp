// Fill out your copyright notice in the Description page of Project Settings.


#include "TickSchedulerSubsystem.h"

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

void UTickSchedulerSubsystem::RegisterActor(AActor* Actor, ESchedulePriority SchedulePriority)
{
	Actor->SetActorTickEnabled(false);
	m_Queue.RegisterActor(Actor, SchedulePriority);
}

void UTickSchedulerSubsystem::UnregisterActor(AActor* Actor, bool ReactivateTick /* = false*/)
{
	m_Queue.UnregisterActor(Actor);
	Actor->SetActorTickEnabled(ReactivateTick);
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