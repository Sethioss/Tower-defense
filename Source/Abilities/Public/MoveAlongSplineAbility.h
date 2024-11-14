// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "MoveAlongSplineAbility.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ABILITIES_API UMoveAlongSplineAbility : public UAbility
{
	GENERATED_BODY()

	virtual void PrepareBuffers(AActor* Instigator, AActor* Target = nullptr) override;

	virtual void TriggerAbility(AActor* Instigator, TArray<float>& RelevantValues, AActor* Target = nullptr) override;
	
	virtual void PostTrigger(AActor* Instigator, TArray<float>& RelevantValues, AActor* Target = nullptr) override;
};
