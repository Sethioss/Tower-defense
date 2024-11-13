// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveAlongSplineAbility.h"

//0 = Speed; 1 = PosOnSpline
void UMoveAlongSplineAbility::TriggerAbility(AActor* Instigator, TArray<float>& RelevantStats)
{
	Super::TriggerAbility(Instigator, RelevantStats);
	if (RelevantStats.Num() > 1)
	{
		//RelevantStats[1] = RelevantStats[0] + RelevantStats[1];
		RelevantStats[1] = FMath::Min(RelevantStats[0] + RelevantStats[1], 5000.0f);
	}

}
