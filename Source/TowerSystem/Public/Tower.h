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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int BuyPrice = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Upgradeprice = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Level = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AtkPower = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AtkRate = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AoeSize = 0.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<class UStaticMeshComponent> MeshComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
