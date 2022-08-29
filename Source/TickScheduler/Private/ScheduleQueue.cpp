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
	SortByPriority();
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

/*
* Predicate returns true if lhs has a lower priority than rhs
* m_ScheduledInterface will we be sorted by ascending Priority
* Lower Priority will be first
*/
void ScheduleQueue::SortByPriority()
{
	m_ScheduledInterface.Sort([](const ITickSchedulerInterface& lhs, const ITickSchedulerInterface& rhs)
	{
		return lhs.GetSchedulePriority() < rhs.GetSchedulePriority();
	});
}

/*
* Predicate returns true if lhs has a higher priority than rhs
* m_ScheduledInterface will we be sorted by descending Priority
* Higher Priority will be first
*/
void ScheduleQueue::SortByPriorityReverse()
{
	m_ScheduledInterface.Sort([](const ITickSchedulerInterface& lhs, const ITickSchedulerInterface& rhs)
	{
		return lhs.GetSchedulePriority() > rhs.GetSchedulePriority();
	});
}

/*
* Predicate returns true if lhs is nearer to m_RegisteredPlayer than rhs
* m_ScheduledInterface will be sorted by ascending Distance
* Lower Distance will be first
*/
void ScheduleQueue::SortByDistance()
{
	m_ScheduledInterface.Sort([&](const ITickSchedulerInterface& lhs, const ITickSchedulerInterface& rhs)
	{
		float DistanceFromLhs = lhs.GetActor()->GetDistanceTo(m_RegisteredPlayer);
		float DistanceFromRhs = rhs.GetActor()->GetDistanceTo(m_RegisteredPlayer);
		return DistanceFromLhs < DistanceFromRhs;
	});
}

/*
* Predicate returns true if lhs is further to m_RegisteredPlayer than rhs
* m_ScheduledInterface will be sorted by descending Distance
* Higher Distance will be first
*/
void ScheduleQueue::SortByDistanceReverse()
{
	m_ScheduledInterface.Sort([&](const ITickSchedulerInterface& lhs, const ITickSchedulerInterface& rhs)
	{
		float DistanceFromLhs = lhs.GetActor()->GetDistanceTo(m_RegisteredPlayer);
		float DistanceFromRhs = rhs.GetActor()->GetDistanceTo(m_RegisteredPlayer);
		return DistanceFromLhs > DistanceFromRhs;
	});
}