// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Path.h"
#include "LevelElementsManager.generated.h"

UCLASS()
class TOWERDEFENSE_API ALevelElementsManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelElementsManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	static ALevelElementsManager* Instance;

public:	
	UFUNCTION(BlueprintCallable, Category = "LevelManagerInstance")
	static ALevelElementsManager* GetInstance();

	UPROPERTY(EditAnywhere)
	TObjectPtr<APath> LvlPath;
};
