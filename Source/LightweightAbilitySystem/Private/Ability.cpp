// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability.h"

void UAbility::TriggerAbility(AActor* Instigator)
{
	UE_LOG(AbilitySystemLog, Log, TEXT("Launching %s abilitiy!"), *AbilityName.ToString());
}
