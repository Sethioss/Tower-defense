// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "LevelElementsManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API ULevelElementsManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;

    void FindPathActor();

    UPROPERTY()
    class APath* PathActor;

    static ULevelElementsManagerSubsystem* Get(const UWorld* World);
	
};
