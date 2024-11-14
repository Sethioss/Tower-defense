// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityDebuggerActor.h"
#include "Kismet/GameplayStatics.h"

AAbilityDebuggerActor* AAbilityDebuggerActor::Instance = nullptr;

// Sets default values
AAbilityDebuggerActor::AAbilityDebuggerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AAbilityDebuggerActor::BeginPlay()
{
	Super::BeginPlay();

	if (!Instance)
	{
		Instance = this;
		Instance->AddToRoot();
	}
}

void AAbilityDebuggerActor::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Instance->RemoveFromRoot();
	Instance = nullptr;
}

void AAbilityDebuggerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

AAbilityDebuggerActor* AAbilityDebuggerActor::GetInstance()
{
	return Instance;
}

void AAbilityDebuggerActor::DebugSphere(FVector Location, float Radius)
{
	DrawDebugSphere(GetWorld(), Location, Radius, 8, FColor::Purple, false, 0.1f, 0U, 2.0f);
}
