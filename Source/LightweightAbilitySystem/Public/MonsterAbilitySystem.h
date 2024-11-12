// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem.h"
#include "MonsterAbilitySystem.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FMonsterAbilityStats
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 1.0f;
};

UCLASS()
class LIGHTWEIGHTABILITYSYSTEM_API UMonsterAbilitySystem : public UAbilitySystem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilitySystemStats")
	FMonsterAbilityStats Stats;

	UFUNCTION(BlueprintCallable)
	inline FMonsterAbilityStats GetStats() { return Stats; }

	TObjectPtr<class AMonster> SystemOwner = nullptr;

protected:
	virtual void BeginPlay() override;

	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
