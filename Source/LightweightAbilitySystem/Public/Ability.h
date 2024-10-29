// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LightWeightAbilitySystemCore.h"
#include "Ability.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class LIGHTWEIGHTABILITYSYSTEM_API UAbility : public UObject
{
	GENERATED_BODY()
	
public:
	FText AbilityName;
	int Cost = 0;

	UFUNCTION()
	virtual void TriggerAbility(AActor* Instigator);
};
