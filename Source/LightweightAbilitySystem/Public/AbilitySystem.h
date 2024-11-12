// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LightWeightAbilitySystemCore.h"
#include "AbilitySystem.generated.h"

UCLASS( BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIGHTWEIGHTABILITYSYSTEM_API UAbilitySystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbilitySystem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void TriggerAbility(TObjectPtr<class UAbility> AbilityToLaunch, TObjectPtr<AActor> Instigator, TObjectPtr<UClass> InstigatorClassType = nullptr);

		
};
