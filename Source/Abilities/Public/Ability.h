// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LightweightAbilitySystem/Public/LightWeightAbilitySystemCore.h"
#include "LightweightAbilitySystem/Public/AbilityStatSet.h"
#include "Ability.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ABILITIES_API UAbility : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	FText AbilityName;
	UPROPERTY(EditAnywhere)
	int Cost = 0;

	UPROPERTY(EditAnywhere)
	bool bDebugAbility = false;

	UAbility();

	UFUNCTION()
	virtual void TriggerAbility(AActor* Instigator, TArray<FAbilityStat>& RelevantStats, TArray<float>& RelevantValues);

	UFUNCTION()
	virtual void PostTrigger(AActor* Instigator, TArray<FAbilityStat>& RelevantStats, TArray<float>& RelevantValues);

	UFUNCTION(BlueprintImplementableEvent)
	void OnAbilityTrigger(AActor* Instigator);
};
