// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthCore.generated.h"

UCLASS()
class TOWERDEFENSE_API AHealthCore : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealthCore();

	UPROPERTY(VisibleAnywhere)
	class UHealthComponent* HealthComp = nullptr;

	UPROPERTY(EditInstanceOnly)
	class UStaticMeshComponent* Mesh = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
