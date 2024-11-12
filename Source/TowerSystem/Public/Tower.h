// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tower.generated.h"

UCLASS(Blueprintable, BlueprintType)
class TOWERSYSTEM_API ATower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<class UStaticMeshComponent> MeshComp;

	UPROPERTY(EditAnywhere)
	TObjectPtr<class UAbilitySystem> AbilitySystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UAbility> ShootingAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UAbility> EnemyCheckAbility;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Init();

private:
	FTimerHandle CheckForEnemiesHandle;

};
