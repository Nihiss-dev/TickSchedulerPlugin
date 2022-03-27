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

void UTickSchedulerSubsystem::RegisterActor(AActor* Actor)
{
	Actor->SetActorTickEnabled(false);
	m_RegisteredActors.Add(Actor);

	SortActors();
}

void UTickSchedulerSubsystem::UnregisterActor(AActor* Actor, bool ReactivateTick /* = false*/)
{
	m_RegisteredActors.Remove(Actor);
	Actor->SetActorTickEnabled(ReactivateTick);

	SortActors();
}

void UTickSchedulerSubsystem::RegisterPlayer(AActor* Player)
{
	checkf(m_RegisteredPlayer == nullptr, TEXT("A player is already registered"));

	m_RegisteredPlayer = Player;
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

void UTickSchedulerSubsystem::SortActors()
{
	if (!m_RegisteredPlayer)
		return;
	m_RegisteredActors.Sort([&](const AActor& A, const AActor& B) {
		float DistanceA = A.GetDistanceTo(m_RegisteredPlayer);
		float DistanceB = B.GetDistanceTo(m_RegisteredPlayer);
		return DistanceA > DistanceB;
	});
}