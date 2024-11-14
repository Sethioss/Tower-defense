// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckForSurroundingEnemies.h"
#include "AbilityStatSet.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "AbilityDebuggerActor.h"

void UCheckForSurroundingEnemies::PrepareBuffers(AActor* Instigator, AActor* Target)
{
	Super::PrepareBuffers(Instigator, Target);

	InstigatorAS->InitStatBuffer(1, InstigatorAS->RelevantStatBuffer);
	InstigatorAS->RegisterStatForAbility("AoeSize");
}

void UCheckForSurroundingEnemies::TriggerAbility(AActor* Instigator, TArray<float>& RelevantValues, AActor* Target)
{
	Super::TriggerAbility(Instigator, RelevantValues);

	if (bDebugAbility)
	{
		AAbilityDebuggerActor::GetInstance()->DebugSphere(FVector(RelevantValues[0], RelevantValues[1], RelevantValues[2]), InstigatorAS->RelevantStatBuffer[0].Value);
	}
}

void UCheckForSurroundingEnemies::PostTrigger(AActor* Instigator, TArray<float>& RelevantValues, AActor* Target)
{
	Super::PostTrigger(Instigator, RelevantValues);
}
