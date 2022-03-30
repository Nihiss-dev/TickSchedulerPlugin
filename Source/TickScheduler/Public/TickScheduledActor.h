// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScheduleQueue.h"
#include "TickScheduledActor.generated.h"

UCLASS()
class TICKSCHEDULER_API ATickScheduledActor : public AActor
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
	bool m_UseTickManager = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tick")
	ESchedulePriority m_SchedulePriority;
};
