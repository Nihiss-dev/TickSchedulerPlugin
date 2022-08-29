// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ScheduleQueue.generated.h"

class ATickScheduledActor;
class ITickSchedulerInterface;

UENUM(BlueprintType)
enum class ESchedulePriority : uint8
{
	SCHEDULE_PRIORITY_NONE = 0x00,
	SCHEDULE_PRIORITY_HIGH = 0x01,
	SCHEDULE_PRIORITY_NORMAL = 0x02,
	SCHEDULE_PRIORITY_LOW = 0x04,
};

/**
 * 
 */
class TICKSCHEDULER_API ScheduleQueue
{
public:
	ScheduleQueue();
	~ScheduleQueue();

	void RegisterPlayer(AActor* Player);
	void RegisterInterface(ITickSchedulerInterface* toRegister);
	void UnregisterInterface(ITickSchedulerInterface* toUnregister);
	void ClearQueue();

	void Update(float DeltaTime);
	void SortByPriority();
	void SortByPriorityReverse();
	void SortByDistance();
	void SortByDistanceReverse();

private:
	TArray<ITickSchedulerInterface*> m_ScheduledInterface;
	AActor* m_RegisteredPlayer;
};
