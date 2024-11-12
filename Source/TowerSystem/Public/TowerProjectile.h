// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TowerProjectile.generated.h"

UCLASS()
class TOWERSYSTEM_API ATowerProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATowerProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<class UStaticMeshComponent> MeshComp;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UAbility> SpawnAbility;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UAbility> TraversalAbility;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UAbility> HitAbility;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
