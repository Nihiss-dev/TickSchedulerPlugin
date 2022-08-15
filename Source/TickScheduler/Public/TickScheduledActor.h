// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScheduleQueue.h"
#include "TickSchedulerInterface.h"
#include "TickScheduledActor.generated.h"

/*
* This class is used to check if everything work as intended
* It may also be used as a sample in case someone would like to implement the ITickSchedulerInterface themself
* Otherwise someone may use ATickScheduledActor as a base class for all Actor they want their tick to be managed
*/

UCLASS()
class TICKSCHEDULER_API ATickScheduledActor : public AActor, public ITickSchedulerInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATickScheduledActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tick")
	ESchedulePriority m_SchedulePriority;

	virtual const AActor* GetActor() const override { return this; }
	virtual AActor* GetActor() override { return this; }
	virtual const ESchedulePriority& GetSchedulePriority() const override { return m_SchedulePriority; }
	virtual ESchedulePriority& GetSchedulePriority() override { return m_SchedulePriority; }
};
