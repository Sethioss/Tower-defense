// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem.h"
#include "AbilityStatSet.h"
#include "Abilities/Public/Ability.h"

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

void UAbilitySystem::TriggerAbility(UAbility* AbilityToLaunch, AActor* Instigator, TArray<FAbilityStat>& RelevantStats, TArray<float>& RelevantValues)
{
	AbilityToLaunch->TriggerAbility(Instigator, RelevantStats, RelevantValues);
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
	float Value = RetrieveStatValueFromName(StatName);
	if (Value != SEARCH_FAILED)
	{
		OutValue = Value;
		return true;
	}
	return false;
}

bool UAbilitySystem::RetrieveStatFromName(FName StatName, FAbilityStat& OutStat)
{
	for (int i = 0; i < EffectiveSets.Num(); i++)
	{
		for (int j = 0; j < EffectiveSets[i]->AbilityStatSet.Num(); j++)
		{
			if (StatName.IsEqual(EffectiveSets[i]->AbilityStatSet[j].Name, ENameCase::IgnoreCase))
			{
				OutStat = EffectiveSets[i]->AbilityStatSet[j];
				return true;
			}
		}
	}
	UE_LOG(AbilitySystemWarning, Warning, TEXT("The stat %s couldn't be found. Make sure it is correctly defined in the stat sets. \n Also make sure that PassDefaultStatSetsToEffectiveStatSets() has been called beforehand"), *StatName.ToString());
	return false;
}

float UAbilitySystem::RetrieveStatValueFromName(FName StatName)
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
	UE_LOG(AbilitySystemWarning, Warning, TEXT("The stat %s couldn't be found. Make sure it is correctly defined in the stat sets. \n Also make sure that PassDefaultStatSetsToEffectiveStatSets() has been called beforehand"), *StatName.ToString());
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
	UE_LOG(AbilitySystemWarning, Warning, TEXT("The stat %s couldn't be found. Make sure it is correctly defined in the stat sets. \n Also make sure that PassDefaultStatSetsToEffectiveStatSets() has been called beforehand"), *StatName.ToString());
	return false;
}

void UAbilitySystem::InitStatBuffer(int NumberOfStats, TArray<FAbilityStat>& StatBuffer)
{
	StatBuffer.Reserve(NumberOfStats);
}

void UAbilitySystem::InitValueBuffer(int NumberOfStats, TArray<float>& ValueBuffer)
{
	ValueBuffer.Reserve(NumberOfStats);
}

void UAbilitySystem::RegisterValueForAbility(float Value)
{
	RelevantValueBuffer.Add(Value);
}

void UAbilitySystem::RegisterStatForAbility(const FName StatName, bool bIsEditedByAbility)
{
	FAbilityStat* Stat = new FAbilityStat();
	if (RetrieveStatFromName(StatName, *Stat))
	{
		Stat->bEditedByAbility = bIsEditedByAbility;
		RelevantStatBuffer.Add(*Stat);
	}
}

//TODO: Use a template to make these functions into one
void UAbilitySystem::EmptyStatBuffer(TArray<FAbilityStat>& Buffer)
{
	Buffer.Empty();
}

void UAbilitySystem::EmptyValueBuffer(TArray<float>& Buffer)
{
	Buffer.Empty();
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

