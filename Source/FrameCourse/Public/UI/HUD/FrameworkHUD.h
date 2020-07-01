// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FrameworkHUD.generated.h"

/**
 * 
 */
UCLASS()
class FRAMECOURSE_API AFrameworkHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Framework")
		TSubclassOf<class UFHUDUserWidget> HUDWidgetClass;

protected:
	virtual void BeginPlay() override;
	
};
