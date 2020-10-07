// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgetEx.h"

void UUserWidgetEx::RemoveFromParent()
{
	UUserWidget::RemoveFromParent();
	OnRemovedFromParent.Broadcast(this);
}