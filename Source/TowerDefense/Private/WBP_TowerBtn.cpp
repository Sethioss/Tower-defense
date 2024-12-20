// Fill out your copyright notice in the Description page of Project Settings.


#include "WBP_TowerBtn.h"
#include "Components/ButtonSlot.h"
#include "Components/Image.h"
#include "ATDPlayerController.h"

DEFINE_LOG_CATEGORY(TowerSelectionLog)
DEFINE_LOG_CATEGORY(TowerSelectionWarning)
DEFINE_LOG_CATEGORY(TowerSelectionError)

UWBP_TowerBtn::UWBP_TowerBtn()
{
    static ConstructorHelpers::FObjectFinder<UTexture2D> DefaultTexture(TEXT("/Engine/EngineResources/DefaultTexture"));
    if (DefaultTexture.Succeeded())
    {
        ButtonTexture = DefaultTexture.Object;
    }

    OnClicked.AddDynamic(this, &UWBP_TowerBtn::SetSelectedTower);
    UpdateButtonImage();
}

UWBP_TowerBtn::~UWBP_TowerBtn()
{
    OnClicked.RemoveAll(this);
}

void UWBP_TowerBtn::SetSelectedTower()
{
    AATDPlayerController* Controller = Cast<AATDPlayerController>(GetWorld()->GetFirstPlayerController());
    if (Controller)
    {
        UE_LOG(TowerSelectionLog, Log, TEXT("Changed selected tower to: %s"), *RelatedTower.Get()->GetName());
        Controller->SelectedTower = RelatedTower;
    }
}

void UWBP_TowerBtn::UpdateButtonImage()
{
    if (ButtonTexture)
    {
        FButtonStyle Style;
        FSlateBrush Brush;

        
        Brush.SetResourceObject(ButtonTexture);
        Brush.SetImageSize(ImageSize);
        Brush.DrawAs = ESlateBrushDrawType::RoundedBox;

        //Normal
        Brush.TintColor = FLinearColor(1.0f, 1.0f, 1.0f);
        Style.SetNormal(Brush);

        //Hovered
        Brush.TintColor = FLinearColor(0.7f, 0.7f, 0.7f);
        Style.SetHovered(Brush);

        //Pressed
        Brush.TintColor = FLinearColor(0.4f, 0.4f, 0.4f);
        Style.SetPressed(Brush);

        SetStyle(Style);
    }
}

#if WITH_EDITOR
void UWBP_TowerBtn::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

    if (PropertyName == GET_MEMBER_NAME_CHECKED(UWBP_TowerBtn, ButtonTexture))
    {
;       UpdateButtonImage();
    }
}
#endif