// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability.h"

void UAbility::TriggerAbility(AActor* Instigator)
{
	OnAbilityTrigger();
	UE_LOG(AbilitySystemLog, Log, TEXT("Launching %s ability!"), *GetName());
}
