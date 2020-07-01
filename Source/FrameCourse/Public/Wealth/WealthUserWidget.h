// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WealthUserWidget.generated.h"

class UImage;
class UOverlay;

/**
 * 
 */
UCLASS()
class FRAMECOURSE_API UWealthUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;

	void AssignTexture(UTexture2D* InTexture);
	void AssignContent(UUserWidget* InWidget);

public:
	UPROPERTY(Meta = (BindWidget))
		UImage* ImageTex;
	
	UPROPERTY(Meta = (BindWidget))
		UOverlay* ContentBox;
};
