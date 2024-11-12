// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem.h"
#include "Ability.h"

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
	UE_LOG(AbilitySystemLog, Log, TEXT("Ability system logging!"));
	UE_LOG(AbilitySystemWarning, Warning, TEXT("Ability system warning!"));
	UE_LOG(AbilitySystemError, Error, TEXT("Ability system error!"));

	// ...
	
}


// Called every frame
void UAbilitySystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAbilitySystem::TriggerAbility(TObjectPtr<UAbility> AbilityToLaunch, TObjectPtr<AActor> Instigator, TObjectPtr<UClass> InstigatorClassType)
{
	AbilityToLaunch.Get()->TriggerAbility(Instigator);
}

