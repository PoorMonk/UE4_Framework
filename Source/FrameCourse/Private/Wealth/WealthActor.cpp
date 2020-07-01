// Fill out your copyright notice in the Description page of Project Settings.


#include "Wealth/WealthActor.h"
#include "Components/StaticMeshComponent.h"
#include "FCommonObject.h"
#include "TimerManager.h"
#include "Engine/ObjectLibrary.h"
#include "Wealth/WealthUserWidget.h"
#include "Engine/StreamableManager.h"

// Sets default values
AWealthActor::AWealthActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));

	WorkMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WorkMesh"));
	WorkMesh->SetupAttachment(RootComponent);
}

void AWealthActor::WealthState()
{
	UStaticMesh* BlockMesh = FindObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Resource/SCTanks/Meshes/SK_SCT_Block.SK_SCT_Block'"));
	if (!BlockMesh)
	{
		FHelper::Debug("FindObject BlockMesh Failed!");
	}
	BlockMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Resource/SCTanks/Meshes/SK_SCT_Block.SK_SCT_Block'"));
	//BlockMesh = FindObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/Resource/SCTanks/Meshes/SK_SCT_Block.SK_SCT_Block'"));

	WorkMesh->SetStaticMesh(BlockMesh);
}

// Called when the game starts or when spawned
void AWealthActor::BeginPlay()
{
	Super::BeginPlay();
	
	//WealthState();
	ObjectLibraryOperate();
	StreamableManagerOperate();

	//FTimerDelegate UpdateMeshDele = FTimerDelegate::CreateUObject(this, &AWealthActor::UpdateMesh);
	//GetWorld()->GetTimerManager().SetTimer(UpdateMeshHandle, UpdateMeshDele, 1.f, true);
}

// Called every frame
void AWealthActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWealthActor::UpdateMesh()
{
	if (WealthData && WealthData->WealthGroup.Num() > 0)
	{
		UStaticMesh* FactMesh = LoadObject<UStaticMesh>(nullptr, *WealthData->WealthGroup[MeshIndex].WealthPath.ToString());
		WorkMesh->SetStaticMesh(FactMesh);

		MeshIndex = (MeshIndex + 1) >= WealthData->WealthGroup.Num() ? 0 : (MeshIndex + 1);
	}
}

void AWealthActor::ObjectLibraryOperate()
{
	if (!ObjectLibrary)
	{
		ObjectLibrary = UObjectLibrary::CreateLibrary(UObject::StaticClass(), false, false);
		ObjectLibrary->AddToRoot();
	}

	//搜索所有Texture的路径
	ObjectLibrary->LoadAssetDataFromPath(TEXT("/Game/Resource/UI/Texture/MenuTex"));

	TArray<FAssetData> TextureData;
	ObjectLibrary->GetAssetDataList(TextureData);

	for (int32 i = 0; i < TextureData.Num(); ++i)
	{
		//FHelper::Debug(TextureData[i].ToSoftObjectPath().ToString(), 20.f);
		TexturePath.AddUnique(TextureData[i].ToSoftObjectPath());
	}
}

void AWealthActor::AssignWealthWidget(UWealthUserWidget* InWidget)
{
	WealthWidget = InWidget;
}

void AWealthActor::StreamableManagerOperate()
{
	//创建加载管理器
	WealthLoader = new FStreamableManager();
	//执行异步加载，添加资源链接数组和加载完成回调函数
	WealthHandle = WealthLoader->RequestAsyncLoad(TexturePath, FStreamableDelegate::CreateUObject(this, &AWealthActor::StreamableManagerLoadComplete));
}

void AWealthActor::StreamableManagerLoadComplete()
{
	TArray<UObject*> OutObjects;
	WealthHandle->GetLoadedAssets(OutObjects);
	for (int32 i = 0; i < OutObjects.Num(); ++i)
	{
		UTexture2D* WorkTexture = Cast<UTexture2D>(OutObjects[i]);
		if (WorkTexture)
		{
			TextureGroup.Add(WorkTexture);
		}
	}

	FTimerDelegate UpdateTextureDele = FTimerDelegate::CreateUObject(this, &AWealthActor::UpdateTexture);
	GetWorld()->GetTimerManager().SetTimer(UpdateTextureHandle, UpdateTextureDele, 0.5f, true);
}

void AWealthActor::UpdateTexture()
{
	if (!WealthWidget)
	{
		return;
	}

	WealthWidget->AssignTexture(TextureGroup[TextureIndex]);
	TextureIndex = (TextureIndex + 1) >= TextureGroup.Num() ? 0 : (TextureIndex + 1);
}

