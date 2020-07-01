// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SrcActor.generated.h"

UCLASS()
class FRAMECOURSE_API ASrcActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASrcActor();

	UFUNCTION()
		void UFunOne();

	UFUNCTION()
		void UFunTwo(FString strInfo, int32& value);

	UFUNCTION()
		bool UFunThree(FString strInfo, int32 value);

	UFUNCTION()
		int32 UFunFour(FString strInfo, int32& value);

public:
	UPROPERTY(EditAnywhere)
		FString ActorName;

	UPROPERTY(EditAnywhere)
		bool IsActive;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
