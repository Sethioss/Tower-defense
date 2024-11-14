// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

LIGHTWEIGHTABILITYSYSTEM_API DECLARE_LOG_CATEGORY_EXTERN(AbilitySystemLog, Log, All);
LIGHTWEIGHTABILITYSYSTEM_API DECLARE_LOG_CATEGORY_EXTERN(AbilitySystemWarning, Warning, All);
LIGHTWEIGHTABILITYSYSTEM_API DECLARE_LOG_CATEGORY_EXTERN(AbilitySystemError, Error, All);
/**
 * 
 */

#define SEARCH_FAILED -9999.99f
//#define GETATTRIBUTE(X) AbilitySystem->RetrieveStatValueFromName(#X);
//#define SETATTRIBUTE(X, Y) AbilitySystem->SetStatValue(#X, Y);

class LIGHTWEIGHTABILITYSYSTEM_API LightWeightAbilitySystemCore
{
public:
	LightWeightAbilitySystemCore();
	~LightWeightAbilitySystemCore();
};
