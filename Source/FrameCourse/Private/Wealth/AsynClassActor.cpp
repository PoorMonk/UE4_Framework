// Fill out your copyright notice in the Description page of Project Settings.


#include "Wealth/AsynClassActor.h"
#include "Engine/StreamableManager.h"
#include "Engine/GameEngine.h"
#include "Engine/World.h"
#include "Engine/StreamableManager.h"

// Sets default values
AAsynClassActor::AAsynClassActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AAsynClassActor::LoadWealthCompleted()
{
	TArray<UObject*> WealthObjects;
	WealthHandle->GetLoadedAssets(WealthObjects);
	for (int i = 0; i < WealthObjects.Num(); ++i)
	{
		UClass* WealthClass = Cast<UClass>(WealthObjects[i]);
		//如果UClass是UObject类型，可以用NewObject生成实例，如果是UUserWidget类型，可以用CreateWidget生成实例
		AActor* WealthActor = GetWorld()->SpawnActor<AActor>(WealthClass, FVector(0.f, 0.f, 1000.f), FQuat::Identity.Rotator());
		WealthActors.Push(WealthActor);
	}

	IndexCounter = 0;
}

// Called when the game starts or when spawned
void AAsynClassActor::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<FSoftObjectPath> ObjectWealthPaths;
	for (int i = 0; i < ClassWealthPaths.Num(); ++i)
	{
		ObjectWealthPaths.Push(ClassWealthPaths[i].ToSoftObjectPath());
	}
	WealthHandle = WealthLoader.RequestAsyncLoad(ObjectWealthPaths, FStreamableDelegate::CreateUObject(this, &AAsynClassActor::LoadWealthCompleted));
}

// Called every frame
void AAsynClassActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (WealthHandle->HasLoadCompleted() && WealthActors.Num() > 0)
	{
		if (TimeCounter > 2.f)
		{
			TimeCounter = 0.f;

			WealthActors[IndexCounter]->SetActorLocation(FVector(0.f, 0.f, 1000.f));
			IndexCounter = IndexCounter + 1 >= WealthActors.Num() ? 0 : IndexCounter + 1;
			WealthActors[IndexCounter]->SetActorLocation(GetActorLocation());
		}
		else
		{
			TimeCounter += DeltaTime;
		}
	}
}

