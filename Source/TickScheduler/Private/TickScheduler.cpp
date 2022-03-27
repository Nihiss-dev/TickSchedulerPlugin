// Copyright Epic Games, Inc. All Rights Reserved.

#include "TickScheduler.h"

#define LOCTEXT_NAMESPACE "FTickSchedulerModule"

void FTickSchedulerModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FTickSchedulerModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTickSchedulerModule, TickScheduler)