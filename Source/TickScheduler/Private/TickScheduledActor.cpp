// Fill out your copyright notice in the Description page of Project Settings.


#include "TickScheduledActor.h"

#include "TickSchedulerSubsystem.h"
#include "ScheduleQueue.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ATickScheduledActor::ATickScheduledActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATickScheduledActor::BeginPlay()
{
	Super::BeginPlay();

	RegisterToScheduler();
}

// Called every frame
void ATickScheduledActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

