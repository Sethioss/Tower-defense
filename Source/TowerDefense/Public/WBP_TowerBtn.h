// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Tower.h"
#include "WBP_TowerBtn.generated.h"

TOWERDEFENSE_API DECLARE_LOG_CATEGORY_EXTERN(TowerSelectionLog, Log, All);
TOWERDEFENSE_API DECLARE_LOG_CATEGORY_EXTERN(TowerSelectionWarning, Warning, All);
TOWERDEFENSE_API DECLARE_LOG_CATEGORY_EXTERN(TowerSelectionError, Error, All);

/**
 * 
 */
UCLASS()
class TOWERDEFENSE_API UWBP_TowerBtn : public UButton
{
	GENERATED_BODY()

public:
	UWBP_TowerBtn();
	~UWBP_TowerBtn();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "Button Texture"))
	UTexture2D* ButtonTexture;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ATower> RelatedTower;

	UPROPERTY(EditAnywhere)
	FVector2D ImageSize;

#if WITH_EDITOR
	// Called when a property is changed in the editor
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

protected:

	// Updates the button's appearance with the set texture
	void UpdateButtonImage();

	UFUNCTION()
	void SetSelectedTower();
};
