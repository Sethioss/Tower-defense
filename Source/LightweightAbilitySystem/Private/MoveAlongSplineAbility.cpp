// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveAlongSplineAbility.h"

void UMoveAlongSplineAbility::TriggerAbility(AActor* Instigator, TArray<FAbilityStat>& RelevantStats)
{
	Super::TriggerAbility(Instigator, RelevantStats);
	OnAbilityTrigger(Instigator);

	if (RelevantStats.Num() > 1)
	{
		RelevantStats[1].Value = FMath::Min(RelevantStats[0].Value + RelevantStats[1].Value, 5000.0f);
	}

	PostTrigger(Instigator, RelevantStats);
}

void UMoveAlongSplineAbility::PostTrigger(AActor* Instigator, TArray<FAbilityStat>& RelevantStats)
{
	Super::PostTrigger(Instigator, RelevantStats);
}
