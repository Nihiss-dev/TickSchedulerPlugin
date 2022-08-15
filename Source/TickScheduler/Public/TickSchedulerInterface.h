// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TickSchedulerSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"
#include "TickSchedulerInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTickSchedulerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TICKSCHEDULER_API ITickSchedulerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void RegisterToScheduler()
	{
		UGameInstance* gameInstance = GetActor()->GetGameInstance();
		if (gameInstance)
		{
			UTickSchedulerSubsystem* tickSubSystem = gameInstance->GetSubsystem<UTickSchedulerSubsystem>();
			tickSubSystem->RegisterInterface(this);
		}
	}

	virtual const AActor* GetActor() const = 0;
	virtual AActor* GetActor() = 0;
	virtual const ESchedulePriority& GetSchedulePriority() const = 0;
	virtual ESchedulePriority& GetSchedulePriority() = 0;
};
