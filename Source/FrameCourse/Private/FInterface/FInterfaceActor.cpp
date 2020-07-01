// Fill out your copyright notice in the Description page of Project Settings.


#include "FInterface/FInterfaceActor.h"
#include "Common/FCommonObject.h"

// Sets default values
AFInterfaceActor::AFInterfaceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFInterfaceActor::FFunOne_Implementation(const FString& HitResult)
{
	//FHelper::Debug("FFunOne", 50.f);
}

void AFInterfaceActor::FFunThree_Implementation(const FString& HitResult)
{
	//FHelper::Debug("FFunThree", 50.f);
}

// Called when the game starts or when spawned
void AFInterfaceActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFInterfaceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

