// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TowerSpot.generated.h"

UCLASS()
class TOWERDEFENSE_API ATowerSpot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATowerSpot();

	UPROPERTY(EditInstanceOnly)
	TObjectPtr<class UStaticMeshComponent> SpotMesh = nullptr;

	UPROPERTY(EditInstanceOnly)
	TObjectPtr<class UBoxComponent> BoxComp = nullptr;

	UPROPERTY(EditInstanceOnly)
	TObjectPtr<USceneComponent> TowerSpawnPoint = nullptr;

	UPROPERTY(VisibleAnywhere, Transient)
	TObjectPtr<class ATower> Tower = nullptr;

	UFUNCTION()
	void FillSpotWithTower(TSubclassOf<class ATower> InTower);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	inline virtual bool IsTowerSlotFilled() { return Tower != nullptr; }

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
