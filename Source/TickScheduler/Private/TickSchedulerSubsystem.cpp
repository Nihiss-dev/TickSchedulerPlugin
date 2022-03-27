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

void UTickSchedulerSubsystem::RegisterActor(AActor* actor)
{
	actor->SetActorTickEnabled(false);
	m_RegisteredActors.Add(actor);
}

void UTickSchedulerSubsystem::RegisterPlayer(AActor* player)
{
	checkf(m_RegisteredPlayer == nullptr, TEXT("A player is already registered"));

	m_RegisteredPlayer = player;
}

bool UTickSchedulerSubsystem::Update(float DeltaTime)
{
	for (AActor* actor : m_RegisteredActors)
	{
		UE_LOG(LogTemp, Display, TEXT("Calling Tick"));
		actor->Tick(DeltaTime);
	}
	return true;
}