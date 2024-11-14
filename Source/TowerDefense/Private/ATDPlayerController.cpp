// Fill out your copyright notice in the Description page of Project Settings.


#include "ATDPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "TowerSystem/Public/TowerSpot.h"
#include "TowerSystem/Public/Tower.h"
#include "DrawDebugHelpers.h"

void AATDPlayerController::BeginPlay()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;  // Optional: enables click events
	bEnableMouseOverEvents = true;  // Optional: enables hover events

	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MappingContext, 0);

		UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));
	}

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInput->BindAction(ClickAction, ETriggerEvent::Started, this, &AATDPlayerController::HandleClick);
	}
}

FVector	WorldPosition, WorldDirection;

void AATDPlayerController::HandleClick()
{
	FVector2D MousePosition;
	GetMousePosition(MousePosition.X, MousePosition.Y);
	float MouseX = MousePosition.X;
	float MouseY = MousePosition.Y;
	FHitResult HitResult;

	DeprojectScreenPositionToWorld(MouseX, MouseY, WorldPosition, WorldDirection);

	DrawDebugLine(GetWorld(), WorldPosition, WorldDirection * 10000, FColor::Green, true);
	GetWorld()->LineTraceSingleByChannel(HitResult, WorldPosition, WorldPosition + WorldDirection * 10000,
		ECollisionChannel::ECC_Camera);

	if (HitResult.bBlockingHit)
	{
		ATowerSpot* TowerSpot = Cast<ATowerSpot>(HitResult.GetActor());
		if(TowerSpot && SelectedTower != nullptr)
		{
			TowerSpot->FillSpotWithTower(SelectedTower);
		}
	}
}