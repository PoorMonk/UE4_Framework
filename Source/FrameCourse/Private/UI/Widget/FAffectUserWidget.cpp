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

//��Initialize�г�ʼ������
bool UFAffectUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}

	//��ȡ��һ���ӿؼ�
	RootPanel = Cast<UCanvasPanel>(GetRootWidget());
	if (RootPanel)
	{
		//��ȡ���ؼ��µ�һ���ؼ�
		ImageBG = Cast<UImage>(RootPanel->GetChildAt(0));
	}
	//Ҳ����ͨ����������ȡ�ؼ�
	BtnTwo = (UButton*)GetWidgetFromName(TEXT("ButtonTwo"));

	//�󶨰�ť�¼�
	ButtonOne->OnClicked.__Internal_AddDynamic(this, &UFAffectUserWidget::ButtonOneEvent, FName("ButtonOneEvent"));

	//��ί�еķ�ʽ��
	FScriptDelegate BtnTwoDel;
	BtnTwoDel.BindUFunction(this, "ButtonTwoEvent");
	BtnTwo->OnReleased.Add(BtnTwoDel);

	return true;
}


void UFAffectUserWidget::ButtonOneEvent()
{
	//������ͼƬ
	UTexture2D* NewTex = LoadObject<UTexture2D>(GetWorld(), TEXT("Texture2D'/Game/Resource/UI/Texture/MenuTex/book.book'"));
	if (ImageBG)
	{
		//��Texture���û�ˢ
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
