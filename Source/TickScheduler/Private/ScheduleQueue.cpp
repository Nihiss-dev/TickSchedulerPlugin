// Fill out your copyright notice in the Description page of Project Settings.


#include "ScheduleQueue.h"

ScheduleQueue::ScheduleQueue()
{
}

ScheduleQueue::~ScheduleQueue()
{
}

void ScheduleQueue::RegisterActor(AActor* Actor, ESchedulePriority SchedulePriority)
{
	m_ScheduledEvents.Add({Actor, SchedulePriority});
}

void ScheduleQueue::UnregisterActor(AActor* Actor)
{
	m_ScheduledEvents.RemoveAll([&](const FScheduledEvent& event)
	{
		return event.actor == Actor;
	});
}

void ScheduleQueue::RegisterPlayer(AActor* Player)
{
	checkf(m_RegisteredPlayer == nullptr, TEXT("A player is already registered"));

	m_RegisteredPlayer = Player;
}

void ScheduleQueue::Update(float DeltaTime)
{
	for (FScheduledEvent scheduleEvent : m_ScheduledEvents)
	{
		scheduleEvent.actor->Tick(DeltaTime);
	}
}