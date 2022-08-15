// Fill out your copyright notice in the Description page of Project Settings.


#include "ScheduleQueue.h"
#include "TickSchedulerInterface.h"

ScheduleQueue::ScheduleQueue()
{
}

ScheduleQueue::~ScheduleQueue()
{
}

void ScheduleQueue::RegisterInterface(ITickSchedulerInterface* toRegister)
{
	m_ScheduledInterface.Add(toRegister);
	m_ScheduledInterface.Sort([](const ITickSchedulerInterface& lhs, const ITickSchedulerInterface& rhs)
	{
		return lhs.GetSchedulePriority() < rhs.GetSchedulePriority();
	});
}

void ScheduleQueue::UnregisterInterface(ITickSchedulerInterface* toUnregister)
{
	m_ScheduledInterface.RemoveAllSwap([&](ITickSchedulerInterface* object)
	{
		return object->GetActor() == toUnregister->GetActor();
	}, true);
}

void ScheduleQueue::RegisterPlayer(AActor* Player)
{
	checkf(m_RegisteredPlayer == nullptr, TEXT("A player is already registered"));

	m_RegisteredPlayer = Player;
}

void ScheduleQueue::ClearQueue()
{
	m_ScheduledInterface.Empty();
}

void ScheduleQueue::Update(float DeltaTime)
{
	for (ITickSchedulerInterface* interface : m_ScheduledInterface)
	{
		interface->GetActor()->Tick(DeltaTime);
	}
}