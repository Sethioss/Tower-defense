// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AbilityStatSet.generated.h"

UENUM()
enum class UAbilityStatType
{
	FLOAT = 0,
	INT = 1,
	BOOL = 2
};

USTRUCT(BlueprintType)
struct FAbilityStat
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FName Name = "";

	UPROPERTY(EditAnywhere)
	float Value = 0.0f;

	UPROPERTY(EditAnywhere)
	UAbilityStatType StatType = UAbilityStatType::FLOAT;
};

UCLASS(Blueprintable)
class LIGHTWEIGHTABILITYSYSTEM_API UAbilityStatSet : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Stats")
	FName StatSetName;

	UPROPERTY(EditAnywhere, Category = "Stats")
	TArray<FAbilityStat> AbilityStatSet;
	
};
