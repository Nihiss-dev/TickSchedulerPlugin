// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

	void RegisterActor(AActor* Actor);
	void UnregisterActor(AActor* Actor, bool ReactivateTick = false);
	void RegisterPlayer(AActor* Player);


private:
	bool Update(float DeltaTime);
	void SortActors();

private:
	FDelegateHandle m_TickHandle;
	TArray<AActor*> m_RegisteredActors;
	AActor* m_RegisteredPlayer;
};
