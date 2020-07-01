// Fill out your copyright notice in the Description page of Project Settings.


#include "FInterface/FCallActor.h"
#include "Kismet/GameplayStatics.h"
#include "Common/FCommonObject.h"
#include "FInterface/FInterfaceActor.h"

// Sets default values
AFCallActor::AFCallActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFCallActor::FCallFun(const FString& HitResult)
{
	//FHelper::Debug("FCallFun", 10.f);
}

// Called when the game starts or when spawned
void AFCallActor::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFInterfaceActor::StaticClass(), Actors);
	if (Actors.Num() > 0)
	{
		IFInterface* ActorPtr = Cast<IFInterface>(Actors[0]);
		ActorPtr->Execute_FFunThree(Actors[0], FString("haha"));
		//ActorPtr->
	}
}

// Called every frame
void AFCallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

