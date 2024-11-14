// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "DealDamageAbility.generated.h"

/**
 * 
 */
UCLASS()
class ABILITIES_API UDealDamageAbility : public UAbility
{
	GENERATED_BODY()

public:
	virtual void PrepareBuffers(AActor* Instigator, AActor* Target = nullptr) override;

	virtual void TriggerAbility(AActor* Instigator, TArray<float>& RelevantValues, AActor* Target = nullptr) override;

	virtual void PostTrigger(AActor* Instigator, TArray<float>& RelevantValues, AActor* Target = nullptr) override;
	
};
