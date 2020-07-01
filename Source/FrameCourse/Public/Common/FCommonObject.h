// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/GameEngine.h"

#include "FCommonObject.generated.h"

namespace FHelper
{
	FORCEINLINE void Debug(FString Message, float Duration = 10.0f)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, Duration, FColor::Yellow, Message);
		}
	}
}

/**
 * 
 */
UCLASS()
class FRAMECOURSE_API UFCommonObject : public UObject
{
	GENERATED_BODY()
	
};
