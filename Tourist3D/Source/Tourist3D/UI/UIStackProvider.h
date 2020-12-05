// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "UIStackProvider.generated.h"

UCLASS()
class TOURIST3D_API AUIStackProvider : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUIStackProvider();

	UFUNCTION(BlueprintCallable, Category = "UI Stack Provider")
	UUserWidget* PushWidgetToStack(UUserWidget* Widget, bool ReplaceSameHead = false);

	UFUNCTION(BlueprintCallable, Category = "UI Stack Provider")
	UUserWidget* PushUniqueWidgetToStack(UUserWidget* Widget, bool ReplaceSameHead = false);

	UFUNCTION(BlueprintCallable, Category = "UI Stack Provider")
	void PopWidgetFromStack();

	UFUNCTION(BlueprintCallable, Category = "UI Stack Provider")
	void ClearStack();

	UFUNCTION(BlueprintCallable, Category = "UI Stack Provider")
	void PrintWidgetsStack();

	UPROPERTY(BlueprintReadOnly, Category = "UI Stack Provider")
	TArray<UUserWidget*> WidgetsStack;
};
