// Fill out your copyright notice in the Description page of Project Settings.


#include "SrcActor.h"
#include "FCommonObject.h"

// Sets default values
ASrcActor::ASrcActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ActorName = FString("AScrActor");
	IsActive = true;

}

void ASrcActor::UFunOne()
{
	FHelper::Debug("ASrcActor --> UFunOne");
}

void ASrcActor::UFunTwo(FString strInfo, int32& value)
{
	FHelper::Debug(strInfo + FString("-->") + FString::FromInt(value));
	value = 987;
}

bool ASrcActor::UFunThree(FString strInfo, int32 value)
{
	FHelper::Debug(strInfo + FString("-->") + FString::FromInt(value));
	return true;
}

int32 ASrcActor::UFunFour(FString strInfo, int32& value)
{
	FHelper::Debug(strInfo + FString("-->") + FString::FromInt(value));
	value = 432;
	return 765;
}

// Called when the game starts or when spawned
void ASrcActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASrcActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

