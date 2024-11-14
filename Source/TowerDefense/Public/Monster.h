// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightweightAbilitySystem/Public/AbilitySystem.h"
#include "LightweightAbilitySystem/Public/AbilityStatSet.h"
#include "Abilities/Public/Ability.h"
#include "Monster.generated.h"

UCLASS()
class TOWERDEFENSE_API AMonster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMonster();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UHealthComponent> HealthComp = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UAbility> WalkingAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UAbility> AttackingAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UAbility> DeathAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UAbility> DepleteSlownessAbility;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<class UStaticMeshComponent> MeshComp;

	UPROPERTY(EditAnywhere)
	TObjectPtr<class UAbilitySystem> AbilitySystem;

	virtual void Walk();

	void SetPositionOnLvlPath(TObjectPtr<class USplineComponent> Path, float ProgressionOverride = -1.0f);

	class ULevelElementsManagerSubsystem* LevelElementsManagerCache = nullptr;

	FTimerHandle WalkTimerHandle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
