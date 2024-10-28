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
	class UStaticMeshComponent* SpotMesh = nullptr;

	//UPROPERTY(VisibleAnywhere)
	//Future tower class

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
