// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CommonUtils.generated.h"

/**
 * 
 */
UCLASS()
class TOURIST3D_API UCommonUtils : public UObject
{
    GENERATED_BODY()

    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Common Utils")
    static bool IsDebugBuild();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Common Utils")
	static FString NameArrayToString(const TArray<FName>& StringArray, bool InRelease);
};
