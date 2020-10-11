// Fill out your copyright notice in the Description page of Project Settings.


#include "UIStackProvider.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AUIStackProvider::AUIStackProvider()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AUIStackProvider::AddWidgetToStack(UUserWidget* Widget, bool ReplaceSame)
{
	if (WidgetsStack.Num() > 0 && WidgetsStack.Last()->GetClass() == Widget->GetClass())
	{
		if (!ReplaceSame)
		{
			if (!WidgetsStack.Last()->IsInViewport())
				WidgetsStack.Last()->AddToViewport();
			return;
		}

		RemoveWidgetFromStack();
	}

	Widget->AddToViewport();
	WidgetsStack.Add(Widget);
}

void AUIStackProvider::RemoveWidgetFromStack()
{
	if (WidgetsStack.Num() <= 0) 
	{
		return;
	}

	UUserWidget* Widget = WidgetsStack.Last();
	Widget->RemoveFromParent();
	WidgetsStack.SetNum(WidgetsStack.Num() - 1);
}

void AUIStackProvider::PrintWidgetsStack()
{
	FString Result = TEXT("UIStackProvider: []");
	for (auto& Widget : WidgetsStack) 
	{
		Result += TEXT(" -> [") + Widget->GetName() + TEXT("]");
	}
	UKismetSystemLibrary::PrintString(GetWorld(), *Result, true, true, FLinearColor(0, 0.6, 1, 1), 3);
}