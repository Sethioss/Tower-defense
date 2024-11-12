// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerAbilitySystem.h"
#include "Tower.h"

void UTowerAbilitySystem::BeginPlay()
{
	Super::BeginPlay();

	SystemOwner = Cast<ATower>(GetOwner());
}
