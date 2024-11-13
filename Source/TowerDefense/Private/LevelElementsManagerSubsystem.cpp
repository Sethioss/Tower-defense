// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelElementsManagerSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Path.h"

void ULevelElementsManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

    //TODO: The subsystem can't find actors at this point because they don't seem to have spawned yet. Find a way to defer this function at a point where other classes can use it on Begin Play
    //without needing these classes to actually call FindPathActor();
    //FindPathActor();
}

void ULevelElementsManagerSubsystem::FindPathActor()
{
    if (UWorld* World = GetWorld())
    {
        TArray<AActor*> FoundActors;
        UGameplayStatics::GetAllActorsOfClass(World, APath::StaticClass(), FoundActors);

        if (FoundActors.Num() > 0)
        {
            PathActor = Cast<APath>(FoundActors[0]);
        }
    }
}

ULevelElementsManagerSubsystem* ULevelElementsManagerSubsystem::Get(const UWorld* World)
{
    if (!World)
    {
        return nullptr;
    }

    if (UGameInstance* GameInstance = World->GetGameInstance())
    {
        return GameInstance->GetSubsystem<ULevelElementsManagerSubsystem>();
    }

    return nullptr;
}
