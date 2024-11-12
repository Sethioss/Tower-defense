// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckForSurroundingEnemies.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "TowerSystem/Public/Tower.h"
#include "AbilityDebuggerActor.h"

void UCheckForSurroundingEnemies::TriggerAbility(AActor* Instigator, TArray<float> RelevantStats)
{
	Super::TriggerAbility(Instigator, RelevantStats);
	OnAbilityTrigger();

	ATower* Tower = Cast<ATower>(Instigator);

	if (Tower)
	{
		FVector Pos = Instigator->GetActorLocation();

		if (AAbilityDebuggerActor::GetInstance())
		{
			if (RelevantStats.Num() > 0)
			{
				AAbilityDebuggerActor::GetInstance()->DebugSphere(Pos, RelevantStats[0]);
			}
			else
			{
				UE_LOG(AbilitySystemError, Error, TEXT("There was an issue with the sent relevant stats. Please make sure that the array is correctly set / used."));

			}
		}
		else
		{
			UE_LOG(AbilitySystemError, Error, TEXT("No ability debugger actor was found. Please make sure that there is one in the scene."));
		}
	}
}
