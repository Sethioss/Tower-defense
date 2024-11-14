// Fill out your copyright notice in the Description page of Project Settings.


#include "DecreaseSlownessStatusAbility.h"
#include "AbilityStatSet.h"

void UDecreaseSlownessStatusAbility::PrepareBuffers(AActor* Instigator, AActor* Target)
{
	Super::PrepareBuffers(Instigator, Target);

	InstigatorAS->InitStatBuffer(3, InstigatorAS->RelevantStatBuffer);
	InstigatorAS->RegisterStatForAbility("Slowed", true);
	InstigatorAS->RegisterStatForAbility("SlownessDrtn");
	InstigatorAS->RegisterStatForAbility("SlownessCntd", true);
}

void UDecreaseSlownessStatusAbility::TriggerAbility(AActor* Instigator, TArray<float>& RelevantValues, AActor* Target)
{
	Super::TriggerAbility(Instigator, RelevantValues, Target);

	TArray<FAbilityStat>& RelevantStats = InstigatorAS->RelevantStatBuffer;

	RelevantStats[2].Value -= InstigatorAS->RelevantValueBuffer[0];
	if (RelevantStats[2].Value <= 0)
	{
		RelevantStats[0].Value = 0.0f;
		RelevantStats[2].Value = RelevantStats[1].Value;
	}

	PostTrigger(Instigator, RelevantValues, Target);
}

void UDecreaseSlownessStatusAbility::PostTrigger(AActor* Instigator, TArray<float>& RelevantValues, AActor* Target)
{
	Super::PostTrigger(Instigator, RelevantValues, Target);
}
