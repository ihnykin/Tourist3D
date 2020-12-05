// Fill out your copyright notice in the Description page of Project Settings.


#include "UIStackProvider.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AUIStackProvider::AUIStackProvider()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

UUserWidget* AUIStackProvider::PushWidgetToStack(UUserWidget* Widget, bool ReplaceSameHead)
{
	// Remove or show widget with the same class
	if (WidgetsStack.Num() > 0 && WidgetsStack.Last()->GetClass() == Widget->GetClass())
	{
		if (!ReplaceSameHead)
		{
			if (!WidgetsStack.Last()->IsInViewport())
				WidgetsStack.Last()->AddToViewport();
			return WidgetsStack.Last();
		}

		PopWidgetFromStack();
	}

	Widget->AddToViewport();
	WidgetsStack.Add(Widget);
	return Widget;
}

UUserWidget* AUIStackProvider::PushUniqueWidgetToStack(UUserWidget* Widget, bool ReplaceSameHead)
{
	int32 FoundIdx = INDEX_NONE;
	for (int32 Idx = WidgetsStack.Num() - 1; Idx >= 0; Idx--)
	{
		if (WidgetsStack[Idx]->GetClass() == Widget->GetClass())
		{
			FoundIdx = Idx;
			break;
		}
	}

	// Remove stack head until widget with the same class
	if (FoundIdx != INDEX_NONE)
	{
		for (int32 Idx = WidgetsStack.Num() - 1; Idx >= 0; Idx--)
		{
			if (WidgetsStack[Idx]->GetClass() == Widget->GetClass())
				break;

			PopWidgetFromStack();
		}
	}

	return PushWidgetToStack(Widget, ReplaceSameHead);
}

void AUIStackProvider::PopWidgetFromStack()
{
	if (WidgetsStack.Num() <= 0) 
	{
		return;
	}

	UUserWidget* Widget = WidgetsStack.Last();
	Widget->RemoveFromParent();
	WidgetsStack.SetNum(WidgetsStack.Num() - 1);
}

void AUIStackProvider::ClearStack()
{
	while (WidgetsStack.Num() > 0)
	{
		PopWidgetFromStack();
	}
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