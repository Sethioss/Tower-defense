// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "AbilityStatSet.h"
#include "MoveAlongSplineAbility.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class LIGHTWEIGHTABILITYSYSTEM_API UMoveAlongSplineAbility : public UAbility
{
	GENERATED_BODY()

	virtual void TriggerAbility(AActor* Instigator, TArray<FAbilityStat>& RelevantStats) override;
	
	virtual void PostTrigger(AActor* Instigator, TArray<FAbilityStat>& RelevantStats) override;
};
