// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourcesSubsystem.h"
#include "AbilitySystem.h"

void UResourcesSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UResourcesSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UResourcesSubsystem::RemoveResource(UAbilitySystem* AS)
{
	GoldResource--;
}