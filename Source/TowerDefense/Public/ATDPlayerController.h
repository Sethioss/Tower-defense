// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ATDPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API AATDPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<class UInputMappingContext> MappingContext;

	/** Click Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ClickAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Tests)
	TSubclassOf<class ATower> SelectedTower;

	virtual void BeginPlay() override;
	
	void HandleClick();
};
