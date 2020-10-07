// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidgetEx.generated.h"

/**
 * Extended User Widget class.
 * Supports dispatchers for:
 * - RemoveFromParent
 */
UCLASS()
class TOURIST3D_API UUserWidgetEx : public UUserWidget
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRemovedFromParentEvent, UUserWidget*, Widget);

	UPROPERTY(BlueprintAssignable)
	FRemovedFromParentEvent OnRemovedFromParent;

	virtual void RemoveFromParent() override;	
};
