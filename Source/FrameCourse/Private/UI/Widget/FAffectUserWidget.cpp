// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/FAffectUserWidget.h"
#include "CanvasPanel.h"
#include "Image.h"
#include "Button.h"
#include "UserWidget.h"
#include "CanvasPanelSlot.h"
#include "WidgetTree.h"

UFAffectUserWidget::UFAffectUserWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

//在Initialize中初始化变量
bool UFAffectUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}

	//获取第一个子控件
	RootPanel = Cast<UCanvasPanel>(GetRootWidget());
	if (RootPanel)
	{
		//获取根控件下第一个控件
		ImageBG = Cast<UImage>(RootPanel->GetChildAt(0));
	}
	//也可以通过名字来获取控件
	BtnTwo = (UButton*)GetWidgetFromName(TEXT("ButtonTwo"));

	//绑定按钮事件
	ButtonOne->OnClicked.__Internal_AddDynamic(this, &UFAffectUserWidget::ButtonOneEvent, FName("ButtonOneEvent"));

	//用委托的方式绑定
	FScriptDelegate BtnTwoDel;
	BtnTwoDel.BindUFunction(this, "ButtonTwoEvent");
	BtnTwo->OnReleased.Add(BtnTwoDel);

	return true;
}


void UFAffectUserWidget::ButtonOneEvent()
{
	//加载新图片
	UTexture2D* NewTex = LoadObject<UTexture2D>(GetWorld(), TEXT("Texture2D'/Game/Resource/UI/Texture/MenuTex/book.book'"));
	if (ImageBG)
	{
		//用Texture设置画刷
		ImageBG->SetBrushFromTexture(NewTex);
	}
}

void UFAffectUserWidget::ButtonTwoEvent()
{
	if (ImageDyn)
	{
		return;
	}

	ImageDyn = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());

	UCanvasPanelSlot* DynImageSlot = RootPanel->AddChildToCanvas(ImageDyn);
	DynImageSlot->SetAnchors(FAnchors(0.f));
	DynImageSlot->SetOffsets(FMargin(244.f, 268.f, 100.f, 100.f));
}

void UFAffectUserWidget::ButtonThreeEvent()
{
	if (!ImageDyn)
	{
		return;
	}

	RootPanel->RemoveChild(ImageDyn);
	ImageDyn->ConditionalBeginDestroy();
	ImageDyn = nullptr;
}
