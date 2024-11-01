// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerSpot.h"
#include "Tower.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ATowerSpot::ATowerSpot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SpotMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	SpotMesh->SetupAttachment(RootComponent);

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Component"));
	BoxComp->SetupAttachment(SpotMesh);

	TowerSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("TowerSpawnPoint"));
	TowerSpawnPoint->SetupAttachment(SpotMesh);

}

// Called when the game starts or when spawned
void ATowerSpot::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATowerSpot::FillSpotWithTower(TSubclassOf<ATower> InTower)
{
	if (!IsTowerSlotFilled())
	{
		FActorSpawnParameters SpawnParams;
		FVector Location = TowerSpawnPoint->GetComponentLocation();
		FRotator Rotation = FRotator::ZeroRotator;

		TObjectPtr<ATower> SpawnedTower = GetWorld()->SpawnActor<ATower>(InTower.Get(), Location, Rotation, SpawnParams);
		if (SpawnedTower)
		{
			UE_LOG(LogTemp, Log, TEXT("TowerSlot: I spawned a %s"), *SpawnedTower.GetName());
			Tower = SpawnedTower;
		}
	}

}

// Called every frame
void ATowerSpot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

