// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ResourcesSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UResourcesSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// Begin USubsystem
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	// End USubsystem

	UFUNCTION(BlueprintCallable)
	void RemoveResource(class UAbilitySystem* AS);

private:
	int GoldResource = 999;
	
};
