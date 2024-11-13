// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LightWeightAbilitySystemCore.h"
#include "AbilitySystem.generated.h"

#define SEARCH_FAILED -9999.99f
#define GETATTRIBUTE(X) AbilitySystem->GetStatFromName(#X);
#define SETATTRIBUTE(X, Y) AbilitySystem->SetStatValue(#X, Y);

UCLASS( BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIGHTWEIGHTABILITYSYSTEM_API UAbilitySystem : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAbilitySystem();

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<class UAbilityStatSet>> StatSets;

	UPROPERTY(VisibleAnywhere)
	TArray<class UAbilityStatSet*> EffectiveSets;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	virtual void TriggerAbility(class UAbility* AbilityToLaunch, AActor* Instigator, TArray<float>& RelevantStats);

	UFUNCTION()
	virtual void PassDefaultStatSetsToEffectiveStatSets();

	UFUNCTION(BlueprintCallable)
	virtual bool SetStatFromName(FName StatName, float& OutValue);

	UFUNCTION(BlueprintCallable)
	virtual float GetStatFromName(FName StatName);

	UFUNCTION(BlueprintCallable)
	virtual bool SetStatSetFromName(FName StatSetName, class UAbilityStatSet* OutValue);

	UFUNCTION(BlueprintCallable)
	virtual class UAbilityStatSet* GetStatSetFromName(FName StatSetName);

	UFUNCTION(BlueprintCallable)
	bool SetStatValue(const FName StatName, const float InValue);
};
