// Fill out your copyright notice in the Description page of Project Settings.


#include "Wealth/WealthUserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Wealth/WealthActor.h"
#include "Image.h"
#include "Overlay.h"
#include "OverlaySlot.h"

bool UWealthUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}

	TArray<AActor*> ActArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWealthActor::StaticClass(), ActArray);
	if (ActArray.Num() > 0)
	{
		AWealthActor* WealthActor = Cast<AWealthActor>(ActArray[0]);
		WealthActor->AssignWealthWidget(this);
	}

	return true;
}

void UWealthUserWidget::AssignTexture(UTexture2D* InTexture)
{
	ImageTex->SetBrushFromTexture(InTexture);
}

void UWealthUserWidget::AssignContent(UUserWidget* InWidget)
{
	UOverlaySlot* ContentSlot = ContentBox->AddChildToOverlay(InWidget);
	ContentSlot->SetPadding(FMargin(0.f, 0.f, 0.f, 0.f));
	ContentSlot->SetHorizontalAlignment(HAlign_Fill);
	ContentSlot->SetVerticalAlignment(VAlign_Fill);
}
