// Fill out your copyright notice in the Description page of Project Settings.


#include "TowerProjectile.h"
#include "Components/StaticMeshComponent.h"
#include "Abilities/Public/Ability.h"

// Sets default values
ATowerProjectile::ATowerProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
	MeshComp->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ATowerProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATowerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

