#include "LevelElementsManager.h"
// Fill out your copyright notice in the Description page of Project Settings.

ALevelElementsManager* ALevelElementsManager::Instance = nullptr;

// Sets default values
ALevelElementsManager::ALevelElementsManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ALevelElementsManager::BeginPlay()
{
	Super::BeginPlay();

	if (!Instance)
	{
		Instance = this;
		Instance->AddToRoot();
	}
	
}

void ALevelElementsManager::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	if (Instance)
	{
		Instance->RemoveFromRoot();
	}
}

ALevelElementsManager* ALevelElementsManager::GetInstance()
{
	return Instance;
}

