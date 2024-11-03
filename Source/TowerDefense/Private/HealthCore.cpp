// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthCore.h"
#include "HealthComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AHealthCore::AHealthCore()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	Mesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AHealthCore::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHealthCore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

