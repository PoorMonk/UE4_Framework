// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FInterface.h"
#include "FInterfaceActor.generated.h"

UCLASS()
class FRAMECOURSE_API AFInterfaceActor : public AActor, public IFInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFInterfaceActor();

	virtual void FFunOne_Implementation(const FString& HitResult);
	virtual void FFunThree_Implementation(const FString& HitResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
