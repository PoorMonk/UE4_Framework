// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ReflectObject.generated.h"

UENUM()
enum class ERefState : uint8
{
	None,
	Active,
	Disable
};

/**
 * 
 */
UCLASS()
class FRAMECOURSE_API UReflectObject : public UObject
{
	GENERATED_BODY()
	
public:
	void EchoInfo();
};
