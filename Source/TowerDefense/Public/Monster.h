// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Monster.generated.h"

UCLASS()
class TOWERDEFENSE_API AMonster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMonster();

	UFUNCTION()
	inline UMonsterAbilitySystem* GetAbilitySystem() { return AbilitySystem; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UHealthComponent> HealthComp = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UAbility> WalkingAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UAbility> AttackingAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UAbility> DeathAbility;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<class UStaticMeshComponent> MeshComp;

	UPROPERTY(EditAnywhere)
	TObjectPtr<class UMonsterAbilitySystem> AbilitySystem;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
