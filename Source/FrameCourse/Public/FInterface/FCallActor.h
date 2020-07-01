// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FCallInterface.h"
#include "FCallActor.generated.h"

UCLASS()
class FRAMECOURSE_API AFCallActor : public AActor, public IFCallInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFCallActor();
	//UFUNCTION(BlueprintCallable, Category = "Framewrok")
	virtual void FCallFun(const FString& HitResult) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
