// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/FrameworkHUD.h"
#include "UI/Widget/FHUDUserWidget.h"

void AFrameworkHUD::BeginPlay()
{
	Super::BeginPlay();

	UFHUDUserWidget* HUDWidget = CreateWidget<UFHUDUserWidget>(GetWorld(), HUDWidgetClass);
	HUDWidget->AddToViewport();
}
