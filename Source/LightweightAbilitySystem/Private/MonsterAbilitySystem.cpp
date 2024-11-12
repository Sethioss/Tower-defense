// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAbilitySystem.h"
#include "Monster.h"

void UMonsterAbilitySystem::BeginPlay()
{
	Super::BeginPlay();

	SystemOwner = Cast<AMonster>(GetOwner());
}

void UMonsterAbilitySystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


}
