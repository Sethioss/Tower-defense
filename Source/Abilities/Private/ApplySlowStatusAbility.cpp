// Fill out your copyright notice in the Description page of Project Settings.


#include "ApplySlowStatusAbility.h"
#include "AbilityStatSet.h"

void UApplySlowStatusAbility::PrepareBuffers(AActor* Instigator, AActor* Target)
{
	Super::PrepareBuffers(Instigator, Target);

	InstigatorAS->InitStatBuffer(1, InstigatorAS->RelevantStatBuffer);
	InstigatorAS->RegisterStatForAbility("AoeSize");

	TargetAS->InitStatBuffer(2, TargetAS->RelevantStatBuffer);
	TargetAS->RegisterStatForAbility("Slowed", true);
}

void UApplySlowStatusAbility::TriggerAbility(AActor* Instigator, TArray<float>& RelevantValues, AActor* Target)
{
	Super::TriggerAbility(Instigator, RelevantValues, Target);

	TArray<FAbilityStat>& RelevantStats = InstigatorAS->RelevantStatBuffer;
	TArray<FAbilityStat>& TargetRelevantStats = TargetAS->RelevantStatBuffer;

	TargetRelevantStats[0].Value = 1.0f;

	PostTrigger(Instigator, RelevantValues, Target);
}

void UApplySlowStatusAbility::PostTrigger(AActor* Instigator, TArray<float>& RelevantValues, AActor* Target)
{
	Super::PostTrigger(Instigator, RelevantValues, Target);
}