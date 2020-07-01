// Fill out your copyright notice in the Description page of Project Settings.


#include "DeleEvent/FDReceActor.h"
#include "Common/FCommonObject.h"
#include "DeleEvent/FDeleActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFDReceActor::AFDReceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFDReceActor::EchoInfoOne(FString InfoStr)
{
	//FHelper::Debug(InfoStr, 10.f);
}

void AFDReceActor::EchoInfoTwo(FString InfoStr, int32 Count)
{
	//FHelper::Debug(InfoStr + FString(" -- ") + FString::FromInt(Count), 10.f);
}

bool AFDReceActor::EchoInfoThree(FString InfoStr, int32 Count)
{
	//FHelper::Debug(InfoStr + FString(" -- ") + FString::FromInt(Count), 10.f);
	return true;
}

// Called when the game starts or when spawned
void AFDReceActor::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFDeleActor::StaticClass(), Actors);
	if (Actors.Num() > 0)
	{
		AFDeleActor* DeleActor = Cast<AFDeleActor>(Actors[0]);
		//方法一：TFunction的函数传递
		//DeleActor->RegFunOne([this](FString InfoStr) { EchoInfoOne(InfoStr); });

		//方法二：TMemFunPtrType传递函数
		//DeleActor->RegFunTwo(this, &AFDReceActor::EchoInfoTwo);

		//方法三：FMethodPtr传递函数
		//DeleActor->RegFunThree(this, &AFDReceActor::EchoInfoTwo);

		//DECLARE_DELEGATE_TwoParams(FTempDele, FString, int32)
		//DeleActor->RegFunFour<FTempDele>(this, &AFDReceActor::EchoInfoTwo, FString("RegFunFour"), 24); 

		DeleActor->RegFunFive<bool, FString, int32>([this](FString InfoStr, int32 Count) { return EchoInfoThree(InfoStr, Count); });
	}

}

// Called every frame
void AFDReceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

