// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "CheckForSurroundingEnemies.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTWEIGHTABILITYSYSTEM_API UCheckForSurroundingEnemies : public UAbility
{
	GENERATED_BODY()

public:
	virtual void TriggerAbility(AActor* Instigator) override;
};
