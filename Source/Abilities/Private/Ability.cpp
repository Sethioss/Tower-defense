// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability.h"
#include "AbilitySystem.h"
#include "AbilityStatSet.h"

UAbility::UAbility()
{
	AbilityName = FText::FromString(GetName());
}

void UAbility::PrepareBuffers(AActor* Instigator, AActor* Target)
{
	InstigatorAS = Instigator->GetComponentByClass<UAbilitySystem>();

	if (Target)
	{
		TargetAS = Target->GetComponentByClass<UAbilitySystem>();
	}
}

void UAbility::DebugUsedStatsAndValues(AActor* Instigator, TArray<FAbilityStat>& RelevantStats, TArray<float>& RelevantValues, AActor* Target)
{
	if (bDebugAbility)
	{
		UE_LOG(AbilitySystemLog, Display, TEXT("Ability: %s; Instigator: %s; Stats used in this ability: %i"), *AbilityName.ToString(), *Instigator->GetName(), RelevantStats.Num());
	
		for (int i = 0; i < RelevantStats.Num(); i++)
		{
			UE_LOG(AbilitySystemLog, Display, TEXT("%i: %s (%f)"), i, *RelevantStats[i].Name.ToString(), RelevantStats[i].Value);
		}
	
		UE_LOG(AbilitySystemLog, Display, TEXT("Values used in this ability: %i"), RelevantValues.Num());
	
		for (int i = 0; i < RelevantValues.Num(); i++)
		{
			UE_LOG(AbilitySystemLog, Display, TEXT("%i: %f"), i, RelevantValues[i]);
		}
	}
}

void UAbility::TriggerAbility(AActor* Instigator, TArray<float>& RelevantValues, AActor* Target)
{
	OnAbilityTrigger(Instigator);

	PrepareBuffers(Instigator, Target);

	TArray<FAbilityStat> RelevantStats = InstigatorAS->RelevantStatBuffer;
	DebugUsedStatsAndValues(Instigator, RelevantStats, RelevantValues);
}

void UAbility::PostTrigger(AActor* Instigator, TArray<float>& RelevantValues, AActor* Target)
{
	if (InstigatorAS)
	{
		TArray<FAbilityStat> RelevantStats = InstigatorAS->RelevantStatBuffer;
		for (int i = 0; i < RelevantStats.Num(); i++)
		{
			if (RelevantStats[i].bEditedByAbility)
			{
				InstigatorAS->SetStatValue(RelevantStats[i].Name, RelevantStats[i].Value);
			}
		}
		InstigatorAS->EmptyStatBuffer(InstigatorAS->RelevantStatBuffer);
		InstigatorAS->EmptyValueBuffer(InstigatorAS->RelevantValueBuffer);
	}

	if (Target)
	{
		if (TargetAS)
		{
			for (int i = 0; i < TargetAS->RelevantStatBuffer.Num(); i++)
			{
				if (TargetAS->RelevantStatBuffer[i].bEditedByAbility)
				{
					TargetAS->SetStatValue(TargetAS->RelevantStatBuffer[i].Name, TargetAS->RelevantStatBuffer[i].Value);
				}
			}
			TargetAS->EmptyStatBuffer(TargetAS->RelevantStatBuffer);
			TargetAS->EmptyValueBuffer(TargetAS->RelevantValueBuffer);
		}
	}
}
