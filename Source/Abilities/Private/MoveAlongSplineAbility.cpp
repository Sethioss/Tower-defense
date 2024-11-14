// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveAlongSplineAbility.h"

void UMoveAlongSplineAbility::PrepareBuffers(AActor* Instigator, AActor* Target)
{
	Super::PrepareBuffers(Instigator, Target);

	InstigatorAS->InitStatBuffer(3, InstigatorAS->RelevantStatBuffer);

	InstigatorAS->RegisterStatForAbility("Speed");
	InstigatorAS->RegisterStatForAbility("AdvancementOnSpline", true);
	InstigatorAS->RegisterStatForAbility("Slowed");
}

void UMoveAlongSplineAbility::TriggerAbility(AActor* Instigator, TArray<float>& RelevantValues, AActor* Target)
{
	Super::TriggerAbility(Instigator, RelevantValues);
	OnAbilityTrigger(Instigator);

	TArray<FAbilityStat>& RelevantStats = InstigatorAS->RelevantStatBuffer;

	if (RelevantStats.Num() > 0)
	{
		float AdvancementValue = RelevantStats[2].Value > 0 ? (RelevantStats[0].Value / 2) : RelevantStats[0].Value;
		RelevantStats[1].Value = FMath::Min(AdvancementValue + RelevantStats[1].Value, 5000.0f);
	}

	PostTrigger(Instigator, RelevantValues, Target);
}

void UMoveAlongSplineAbility::PostTrigger(AActor* Instigator, TArray<float>& RelevantValues, AActor* Target)
{
	Super::PostTrigger(Instigator, RelevantValues);
}
