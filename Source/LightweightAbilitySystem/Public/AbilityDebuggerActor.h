// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilityDebuggerActor.generated.h"

UCLASS()
class LIGHTWEIGHTABILITYSYSTEM_API AAbilityDebuggerActor : public AActor
{
	GENERATED_BODY()

private:
	static AAbilityDebuggerActor* Instance;

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;
	
public:	
	// Sets default values for this actor's properties
	AAbilityDebuggerActor();

	static AAbilityDebuggerActor* GetInstance();

	void DebugSphere(FVector Location, float Radius);

};
