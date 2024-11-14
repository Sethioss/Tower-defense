// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveAlongSplineAbility.h"

void UMoveAlongSplineAbility::TriggerAbility(AActor* Instigator, TArray<FAbilityStat>& RelevantStats, TArray<float>& RelevantValues)
{
	Super::TriggerAbility(Instigator, RelevantStats, RelevantValues);
	OnAbilityTrigger(Instigator);

	if (RelevantStats.Num() > 0)
	{
		float AdvancementValue = RelevantStats[2].Value > 0 ? (RelevantStats[0].Value / 2) : RelevantStats[0].Value;
		RelevantStats[1].Value = FMath::Min(AdvancementValue + RelevantStats[1].Value, 5000.0f);
	}

	PostTrigger(Instigator, RelevantStats, RelevantValues);
}

void UMoveAlongSplineAbility::PostTrigger(AActor* Instigator, TArray<FAbilityStat>& RelevantStats, TArray<float>& RelevantValues)
{
	Super::PostTrigger(Instigator, RelevantStats, RelevantValues);
}
