// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "CheckForSurroundingEnemies.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ABILITIES_API UCheckForSurroundingEnemies : public UAbility
{
	GENERATED_BODY()

public:
	virtual void TriggerAbility(AActor* Instigator, TArray<FAbilityStat>& RelevantStats, TArray<float>& RelevantValues) override;
};
