// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "WealthActor.generated.h"

class UStaticMeshComponent;
class UObjectLibrary;
class UTexture2D;
class UWealthUserWidget;
struct FStreamableManager;
struct FStreamableHandle;

USTRUCT()
struct FWealthNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		FName WealthName;

	UPROPERTY(EditAnywhere)
		FStringAssetReference WealthPath;
};

UCLASS()
class FRAMECOURSE_API UWealthData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		TArray<UTexture2D*> WealthTexture;

	UPROPERTY(EditAnywhere)
		TArray<FWealthNode> WealthGroup;
};


UCLASS()
class FRAMECOURSE_API AWealthActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWealthActor();

	void WealthState();
	void UpdateMesh();
	void UpdateTexture();
	void ObjectLibraryOperate();

	void AssignWealthWidget(UWealthUserWidget* InWidget);

	//资源异步加载
	void StreamableManagerOperate();

	//资源异步加载完成
	void StreamableManagerLoadComplete();
	//三种类型转换
	void UObjectUClassUBlueprint();

public:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* WorkMesh;

	UPROPERTY(EditAnywhere)
		UWealthData* WealthData;

	/*UPROPERTY(EditAnywhere)
		FStringAssetReference HandleObjectPath;

	UPROPERTY(EditAnywhere)
		FStringAssetReference HandleActorPath;

	UPROPERTY(EditAnywhere)
		FStringAssetReference HandleWidgetPath;*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	int32 MeshIndex;
	FTimerHandle UpdateMeshHandle;
	FTimerHandle UpdateTextureHandle;
	//对象库，用来读取某以文件夹下的资源
	UObjectLibrary* ObjectLibrary;
	//所有需要的资源路径
	TArray<FSoftObjectPath> TexturePath;
	UWealthUserWidget* WealthWidget;

	FStreamableManager* WealthLoader;
	TSharedPtr<FStreamableHandle> WealthHandle;

	TArray<UTexture2D*> TextureGroup;
	int32 TextureIndex;
};
