// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LightWeightAbilitySystemCore.h"
#include "AbilityStatSet.h"
#include "AbilitySystem.h"
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

	UAbilitySystem* InstigatorAS = nullptr;
	UAbilitySystem* TargetAS = nullptr;

	UFUNCTION()
	virtual void PrepareBuffers(AActor* Instigator, AActor* Target = nullptr);

	UFUNCTION()
	virtual void DebugUsedStatsAndValues(AActor* Instigator, TArray<FAbilityStat>& RelevantStats, TArray<float>& RelevantValues, AActor* Target = nullptr);

	UFUNCTION()
	virtual void TriggerAbility(AActor* Instigator, TArray<float>& RelevantValues, AActor* Target = nullptr);

	UFUNCTION()
	virtual void PostTrigger(AActor* Instigator, TArray<float>& RelevantValues, AActor* Target = nullptr);

	UFUNCTION(BlueprintImplementableEvent)
	void OnAbilityTrigger(AActor* Instigator, AActor* Target = nullptr);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPostAbility(AActor* Instigator, AActor* Target = nullptr);
};
