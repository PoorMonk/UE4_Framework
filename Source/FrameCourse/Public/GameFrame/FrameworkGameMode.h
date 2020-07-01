// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FrameworkGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FRAMECOURSE_API AFrameworkGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
};
