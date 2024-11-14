// Fill out your copyright notice in the Description page of Project Settings.


#include "Monster.h"
#include "LightweightAbilitySystem/Public/Ability.h"
#include "LightweightAbilitySystem/Public/AbilitySystem.h"
//#include "LightweightAbilitySystem/Public/AbilityStatSet.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SplineComponent.h"
#include "HealthComponent.h"
#include "Path.h"
#include "LevelElementsManagerSubsystem.h"

UE_DISABLE_OPTIMIZATION

// Sets default values
AMonster::AMonster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	AbilitySystem = CreateDefaultSubobject<UAbilitySystem>(TEXT("AbilitySystem"));

	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshRef(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if (MeshRef.Object != nullptr)
	{
		MeshComp->SetStaticMesh(MeshRef.Object);
	}
	MeshComp->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMonster::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystem->PassDefaultStatSetsToEffectiveStatSets();
	AbilitySystem->SetStatValue("AdvancementOnSpline", 0.0f);

	LevelElementsManagerCache = ULevelElementsManagerSubsystem::Get(GetWorld());
	if (!LevelElementsManagerCache->PathActor)
	{
		LevelElementsManagerCache->FindPathActor();

		if (LevelElementsManagerCache)
		{
			if (LevelElementsManagerCache->PathActor)
			{
				SetPositionOnLvlPath(LevelElementsManagerCache->PathActor->Path, 0.0f);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("Couldn't do initial SetPosition cause LvlPath is null"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Couldn't do initial SetPosition cause LevelElementsManagerCache is null"));
		}
	}
}

void AMonster::Walk()
{
	AbilitySystem->InitRelevantStatBuffer(2);

	AbilitySystem->RegisterStatForAbility("Speed");
	AbilitySystem->RegisterStatForAbility("AdvancementOnSpline", true);

	AbilitySystem->TriggerAbility(WalkingAbility.GetDefaultObject(), this, AbilitySystem->RelevantStatBuffer);

	AbilitySystem->EmptyStatBuffer();

	if (LevelElementsManagerCache)
	{
		USplineComponent* LevelPath = LevelElementsManagerCache->PathActor->Path;

		if (LevelPath)
		{
			SetPositionOnLvlPath(LevelPath);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("LevelElementsManager instance doesn't have a valid LevelPath property. Aborting monster walking operation"));

		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("LevelElementsManager instance wasn't found, please make sure there is always one in the scene. Aborting monster walking operation"));
	}
}

void AMonster::SetPositionOnLvlPath(TObjectPtr<USplineComponent> LevelPath, float ProgressionOverride)
{

	float Advancement = AbilitySystem->RetrieveStatValueFromName("AdvancementOnSpline");

	FVector NewLocation = LevelPath->GetLocationAtDistanceAlongSpline(
		ProgressionOverride = -1.0f ? Advancement : ProgressionOverride,
		ESplineCoordinateSpace::World
	);

	// Optional: Get rotation to face along spline
	FRotator NewRotation = LevelPath->GetRotationAtDistanceAlongSpline(
		ProgressionOverride = -1.0f ? Advancement : ProgressionOverride,
		ESplineCoordinateSpace::World
	);

	SetActorLocation(NewLocation);
	SetActorRotation(NewRotation);
}

// Called every frame
void AMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Walk();
}

