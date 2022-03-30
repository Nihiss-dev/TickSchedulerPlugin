// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ScheduleQueue.generated.h"

class ATickScheduledActor;

UENUM(BlueprintType)
enum class ESchedulePriority : uint8
{
	SCHEDULE_PRIORITY_LOW,
	SCHEDULE_PRIORITY_NORMAL,
	SCHEDULE_PRIORITY_HIGH
};

struct FScheduledEvent
{
	AActor* actor;
	ESchedulePriority schedulePriority;
};

/**
 * 
 */
class TICKSCHEDULER_API ScheduleQueue
{
public:
	ScheduleQueue();
	~ScheduleQueue();

	void RegisterActor(AActor* Actor, ESchedulePriority SchedulePriority);
	void UnregisterActor(AActor* Actor);
	void RegisterPlayer(AActor* Player);

	void Update(float DeltaTime);

private:
	TArray<FScheduledEvent> m_ScheduledEvents;
	AActor* m_RegisteredPlayer;
};
