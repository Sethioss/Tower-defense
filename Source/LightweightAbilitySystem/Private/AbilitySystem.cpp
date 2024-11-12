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

void UAbilitySystem::TriggerAbility(UAbility* AbilityToLaunch, AActor* Instigator, TArray<float> RelevantStats)
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

bool UAbilitySystem::GetStatFromName(FName StatName, float& OutValue)
{
	for (UAbilityStatSet* StatSet : EffectiveSets)
	{
		for (FAbilityStat Stat : StatSet->AbilityStatSet)
		{
			if (StatName.IsEqual(Stat.Name, ENameCase::IgnoreCase))
			{
				OutValue = Stat.Value;
				return true;
			}
		}
	}
	return false;
}

bool UAbilitySystem::GetStatSetFromName(FName StatSetName, UAbilityStatSet* OutStatSet)
{
	for (UAbilityStatSet* StatSet : EffectiveSets)
	{
		if (StatSet->StatSetName.IsEqual(StatSetName, ENameCase::IgnoreCase))
		{
			OutStatSet = StatSet;
			return true;
		}
	}
	return false;
}

