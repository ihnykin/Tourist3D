// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonUtils.h"

bool UCommonUtils::IsDebugBuild()
{
	if (!UE_BUILD_SHIPPING)
	{
		return true;
	}
	else
	{
		return false;
	}
}

FString UCommonUtils::NameArrayToString(const TArray<FName>& Array, bool InRelease)
{
	if (!InRelease && !IsDebugBuild())
		return {};

	FString Res = TEXT("[");
	for (auto& Item : Array)
	{
		FString ItemStr;
		Item.ToString(ItemStr);
		Res += ItemStr + TEXT("; ");
	}
	return Res + TEXT("]");
}