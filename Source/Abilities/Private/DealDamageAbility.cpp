// Fill out your copyright notice in the Description page of Project Settings.


#include "DealDamageAbility.h"
#include "AbilityStatSet.h"

void UDealDamageAbility::PrepareBuffers(AActor* Instigator, AActor* Target)
{
	Super::PrepareBuffers(Instigator, Target);

	InstigatorAS->InitStatBuffer(1, InstigatorAS->RelevantStatBuffer);
	InstigatorAS->RegisterStatForAbility("Atk");

	TargetAS->InitStatBuffer(1, TargetAS->RelevantStatBuffer);
	TargetAS->RegisterStatForAbility("Health", true);
}

void UDealDamageAbility::TriggerAbility(AActor* Instigator, TArray<float>& RelevantValues, AActor* Target)
{
	Super::TriggerAbility(Instigator, RelevantValues, Target);

	TArray<FAbilityStat>& RelevantStats = InstigatorAS->RelevantStatBuffer;
	TArray<FAbilityStat>& TargetRelevantStats = TargetAS->RelevantStatBuffer;

	TargetRelevantStats[0].Value -= RelevantStats[0].Value;

	PostTrigger(Instigator, RelevantValues, Target);
}

void UDealDamageAbility::PostTrigger(AActor* Instigator, TArray<float>& RelevantValues, AActor* Target)
{
	Super::PostTrigger(Instigator, RelevantValues, Target);
}

