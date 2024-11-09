// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem.h"
#include "TowerAbilitySystem.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FTowerAbilityStats
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BuyPrice = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UpgradePrice = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AtkPower = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AtkRate = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AoeSize = 0.0f;
};

UCLASS(BlueprintType, ClassGroup = (Custom))
class LIGHTWEIGHTABILITYSYSTEM_API UTowerAbilitySystem : public UAbilitySystem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilitySystem")
	FTowerAbilityStats Stats;

	UFUNCTION(BlueprintCallable)
	inline FTowerAbilityStats GetStats() { return Stats; }
};
