// Fill out your copyright notice in the Description page of Project Settings.


#include "DeleEvent/FDeleActor.h"

// Sets default values
AFDeleActor::AFDeleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFDeleActor::RegFunDele(FDE_Dy_S_Zero TargetFun)
{
	TargetFun.ExecuteIfBound();
}

void AFDeleActor::RegFunOne(TFunction<void(FString)> TargetFun)
{
	TFunOne = TargetFun;
	TFunOne(FString("RegFunOne"));
}



// Called when the game starts or when spawned
void AFDeleActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFDeleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

