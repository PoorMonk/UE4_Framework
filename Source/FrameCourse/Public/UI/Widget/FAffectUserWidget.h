// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FAffectUserWidget.generated.h"

class UCanvasPanel;
class UButton;
class UImage;

/**
 * 
 */
UCLASS()
class FRAMECOURSE_API UFAffectUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFAffectUserWidget(const FObjectInitializer& ObjectInitializer);

	//Widget的初始化函数
	virtual bool Initialize() override;

	UFUNCTION(BlueprintCallable, Category = "Widget")
		void ButtonThreeEvent();

	UFUNCTION()
		void ButtonOneEvent();

	UFUNCTION()
		void ButtonTwoEvent();

public:
	//反射绑定，名字要一样
	UPROPERTY(Meta = (BindWidget))
		UButton* ButtonOne;

private:
	UCanvasPanel* RootPanel;
	UButton* BtnTwo;
	UImage* ImageBG;
	UImage* ImageDyn;
};
