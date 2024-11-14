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

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<class UAbilityStatSet>> StatSets;

	UPROPERTY(VisibleAnywhere)
	TArray<class UAbilityStatSet*> EffectiveSets;

	UPROPERTY(Transient)
	TArray<float> RelevantValueBuffer;

	UPROPERTY(Transient)
	TArray<FAbilityStat> RelevantStatBuffer;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	virtual void TriggerAbility(class UAbility* AbilityToLaunch, AActor* Instigator, TArray<float>& RelevantValues, AActor* Target = nullptr);

	UFUNCTION()
	virtual void PassDefaultStatSetsToEffectiveStatSets();

	UFUNCTION(BlueprintCallable)
	virtual bool SetStatFromName(FName StatName, float& OutValue);

	UFUNCTION(BlueprintCallable)
	virtual float RetrieveStatValueFromName(FName StatName);

	UFUNCTION(BlueprintCallable)
	bool RetrieveStatFromName(FName StatName, FAbilityStat& OutStat);

	UFUNCTION(BlueprintCallable)
	virtual bool SetStatSetFromName(FName StatSetName, class UAbilityStatSet* OutValue);

	UFUNCTION(BlueprintCallable)
	virtual class UAbilityStatSet* GetStatSetFromName(FName StatSetName);

	UFUNCTION(BlueprintCallable)
	bool SetStatValue(const FName StatName, const float InValue);

	UFUNCTION(BlueprintCallable)
	void RegisterStatForAbility(const FName StatName, bool bIsEditedByAbility = false);

	UFUNCTION(BlueprintCallable)
	void RegisterValueForAbility(float Value);

	//TODO: Separate Stat and Value buffer by a same class, so we can use the same function for the two buffers, or use a template
	UFUNCTION(BlueprintCallable)
	void InitStatBuffer(int NumberOfStats, TArray<FAbilityStat>& StatBuffer);

	UFUNCTION(BlueprintCallable)
	void InitValueBuffer(int NumberOfStats, TArray<float>& ValueBuffer);

	UFUNCTION(BlueprintCallable)
	void EmptyStatBuffer(TArray<FAbilityStat>& Buffer);

	UFUNCTION(BlueprintCallable)
	void EmptyValueBuffer(TArray<float>& Buffer);
};
