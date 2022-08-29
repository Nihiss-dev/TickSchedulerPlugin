// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ScheduleQueue.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TickSchedulerSubsystem.generated.h"


/**
 * 
 */
UCLASS()
class UTickSchedulerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	void RegisterInterface(ITickSchedulerInterface* toRegister);
	void UnregisterInterface(ITickSchedulerInterface* toUnregister, bool reactivateTick = false);
	void RegisterPlayer(AActor* Player);


private:
	bool Update(float DeltaTime);
private:
	FDelegateHandle m_TickHandle;

	ScheduleQueue m_Queue;
};
