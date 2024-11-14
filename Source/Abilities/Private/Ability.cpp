// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability.h"
#include "AbilitySystem.h"
#include "AbilityStatSet.h"

UAbility::UAbility()
{
	AbilityName = FText::FromString(GetName());
}

void UAbility::TriggerAbility(AActor* Instigator, TArray<FAbilityStat>& RelevantStats, TArray<float>& RelevantValues)
{
	OnAbilityTrigger(Instigator);

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

void UAbility::PostTrigger(AActor* Instigator, TArray<FAbilityStat>& RelevantStats, TArray<float>& RelevantValues)
{
	UAbilitySystem* AbilitySystem = Instigator->GetComponentByClass<UAbilitySystem>();
	if (AbilitySystem)
	{
		for (int i = 0; i < RelevantStats.Num(); i++)
		{
			if (RelevantStats[i].bEditedByAbility)
			{
				AbilitySystem->SetStatValue(RelevantStats[i].Name, RelevantStats[i].Value);
			}
		}
	}
}
