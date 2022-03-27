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

	void RegisterActor(AActor* actor);
	void RegisterPlayer(AActor* player);

private:
	bool Update(float DeltaTime);

private:
	FDelegateHandle m_TickHandle;
	TArray<AActor*> m_RegisteredActors;
	AActor* m_RegisteredPlayer;
};
