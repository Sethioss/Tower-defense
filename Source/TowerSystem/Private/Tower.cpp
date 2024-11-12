// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Components/StaticMeshComponent.h"
#include "LightweightAbilitySystem/Public/TowerAbilitySystem.h"
#include "LightweightAbilitySystem/Public/Ability.h"

// Sets default values
ATower::ATower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	AbilitySystem = CreateDefaultSubobject<UTowerAbilitySystem>(TEXT("TowerAbilitySystem"));

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshRef(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if (MeshRef.Object != nullptr)
	{
		MeshComp->SetStaticMesh(MeshRef.Object);
	}
	MeshComp->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATower::Init()
{
	if (AbilitySystem)
	{
		if (EnemyCheckAbility)
		{
			AActor* TowerActor = this;
			AbilitySystem->TriggerAbility(EnemyCheckAbility.GetDefaultObject(), this, ATower::StaticClass());
		}
	}
}


