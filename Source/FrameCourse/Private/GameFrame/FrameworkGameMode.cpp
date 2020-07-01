// Fill out your copyright notice in the Description page of Project Settings.


#include "FrameworkGameMode.h"
#include "Common/FDataSingletonObject.h"
#include "Engine/GameEngine.h"
#include "Common/FCommonObject.h"

void AFrameworkGameMode::BeginPlay()
{
	Super::BeginPlay();

	UFDataSingletonObject* DataSingleton = Cast<UFDataSingletonObject>(GEngine->GameSingleton);
	//FHelper::Debug(DataSingleton->SourceVector.ToString(), 10.f);
}
