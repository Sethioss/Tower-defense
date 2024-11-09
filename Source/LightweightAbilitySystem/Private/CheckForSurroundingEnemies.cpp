// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckForSurroundingEnemies.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "TowerSystem/Public/Tower.h"
#include "AbilityDebuggerActor.h"

void UCheckForSurroundingEnemies::TriggerAbility(AActor* Instigator)
{
	Super::TriggerAbility(Instigator);
	OnAbilityTrigger();

	ATower* Tower = Cast<ATower>(Instigator);

	if (Tower)
	{
		UTowerAbilitySystem* As = Tower->GetAbilitySystem();
		FVector Pos = Instigator->GetActorLocation();

		if (AAbilityDebuggerActor::GetInstance())
		{
			AAbilityDebuggerActor::GetInstance()->DebugSphere(Pos, As->GetStats().AoeSize);
		}
		else
		{
			UE_LOG(AbilitySystemError, Error, TEXT("No ability debugger actor was found. Please make sure that there is one in the scene."));
		}
	}
}
