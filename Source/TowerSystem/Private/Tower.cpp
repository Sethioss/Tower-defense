// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Components/StaticMeshComponent.h"
#include "AbilitySystem.h"
#include "AbilityStatSet.h"
#include "Ability.h"

// Sets default values
ATower::ATower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	AbilitySystem = CreateDefaultSubobject<UAbilitySystem>(TEXT("AbilitySystem"));

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

void ATower::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorldTimerManager().ClearTimer(CheckEnemiesTimerHandle);
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
		AbilitySystem->PassDefaultStatSetsToEffectiveStatSets();

		float AtkRate = AbilitySystem->RetrieveStatValueFromName("AtkRate");
		GetWorld()->GetTimerManager().SetTimer(CheckEnemiesTimerHandle, this, &ATower::TriggerEnemySearch, AtkRate, true);
	}
}

void ATower::TriggerEnemySearch()
{
	if (AbilitySystem)
	{
		FVector Pos = GetActorLocation();

		if (EnemyCheckAbility)
		{
			AbilitySystem->InitValueBuffer(3, AbilitySystem->RelevantValueBuffer);

			AbilitySystem->RegisterValueForAbility(Pos.X);
			AbilitySystem->RegisterValueForAbility(Pos.Y);
			AbilitySystem->RegisterValueForAbility(Pos.Z);

			AbilitySystem->TriggerAbility(EnemyCheckAbility.GetDefaultObject(), this, AbilitySystem->RelevantValueBuffer);
		}
	}
}


