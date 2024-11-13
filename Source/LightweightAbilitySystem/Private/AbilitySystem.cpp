// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem.h"
#include "Ability.h"
#include "AbilityStatSet.h"

DEFINE_LOG_CATEGORY(AbilitySystemLog);
DEFINE_LOG_CATEGORY(AbilitySystemWarning);
DEFINE_LOG_CATEGORY(AbilitySystemError);

// Sets default values for this component's properties
UAbilitySystem::UAbilitySystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAbilitySystem::BeginPlay()
{
	Super::BeginPlay();
	// ...

}


// Called every frame
void UAbilitySystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAbilitySystem::TriggerAbility(UAbility* AbilityToLaunch, AActor* Instigator, TArray<float>& RelevantStats)
{
	AbilityToLaunch->TriggerAbility(Instigator, RelevantStats);
}

void UAbilitySystem::PassDefaultStatSetsToEffectiveStatSets()
{
	//Should be called only once when the object is spawned, as it is the way to pass the default values of a stat set to a modifiable array
	if (EffectiveSets.IsEmpty())
	{
		for (int i = 0; i < StatSets.Num(); i++)
		{
			UAbilityStatSet* CurrentSet = StatSets[i].GetDefaultObject();

			EffectiveSets.Insert(CurrentSet, 0);
		}
	}
}

bool UAbilitySystem::SetStatFromName(FName StatName, float& OutValue)
{
	float Value = GetStatFromName(StatName);
	if (Value != SEARCH_FAILED)
	{
		OutValue = Value;
		return true;
	}
	return false;
}

float UAbilitySystem::GetStatFromName(FName StatName)
{
	for (int i = 0; i < EffectiveSets.Num(); i++)
	{
		for (int j = 0; j < EffectiveSets[i]->AbilityStatSet.Num(); j++)
		{
			if (StatName.IsEqual(EffectiveSets[i]->AbilityStatSet[j].Name, ENameCase::IgnoreCase))
			{
				return EffectiveSets[i]->AbilityStatSet[j].Value;
			}
		}
	}
	return SEARCH_FAILED;
}

bool UAbilitySystem::SetStatValue(const FName StatName, const float InValue)
{
	for (int i = 0; i < EffectiveSets.Num(); i++)
	{
		for (int j = 0; j < EffectiveSets[i]->AbilityStatSet.Num(); j++)
		{
			if (EffectiveSets[i]->AbilityStatSet[j].Name.IsEqual(StatName, ENameCase::IgnoreCase))
			{
				EffectiveSets[i]->AbilityStatSet[j].Value = InValue;
				return true;
			}
		}
	}
	return false;
}

bool UAbilitySystem::SetStatSetFromName(FName StatSetName, UAbilityStatSet* OutStatSet)
{
	UAbilityStatSet* Set = GetStatSetFromName(StatSetName);
	if (Set)
	{
		OutStatSet = Set;
		return true;
	}

	return false;
}

UAbilityStatSet* UAbilitySystem::GetStatSetFromName(FName StatSetName)
{
	for (int i = 0; i < EffectiveSets.Num(); i++)
	{
		if (EffectiveSets[i]->StatSetName.IsEqual(StatSetName, ENameCase::IgnoreCase))
		{
			return EffectiveSets[i];
		}
	}
	return nullptr;
}

