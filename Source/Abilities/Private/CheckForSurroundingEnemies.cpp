// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckForSurroundingEnemies.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "AbilityStatSet.h"
#include "AbilityDebuggerActor.h"

void UCheckForSurroundingEnemies::TriggerAbility(AActor* Instigator, TArray<FAbilityStat>& RelevantStats, TArray<float>& RelevantValues)
{
	Super::TriggerAbility(Instigator, RelevantStats, RelevantValues);

	if (bDebugAbility)
	{
		AAbilityDebuggerActor::GetInstance()->DebugSphere(FVector(RelevantValues[0], RelevantValues[1], RelevantValues[2]), RelevantStats[0].Value);
	}

	OnAbilityTrigger(Instigator);
}
