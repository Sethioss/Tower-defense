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
	UPROPERTY(EditAnywhere)
	FText AbilityName;
	UPROPERTY(EditAnywhere)
	int Cost = 0;

	UPROPERTY(EditAnywhere)
	bool bDebugAbility = false;

	UAbility();

	UFUNCTION()
	virtual void TriggerAbility(AActor* Instigator, TArray<FAbilityStat>& RelevantStats);

	UFUNCTION()
	virtual void PostTrigger(AActor* Instigator, TArray<FAbilityStat>& RelevantStats);

	UFUNCTION(BlueprintImplementableEvent)
	void OnAbilityTrigger(AActor* Instigator);
};
