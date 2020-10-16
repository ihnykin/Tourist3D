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
