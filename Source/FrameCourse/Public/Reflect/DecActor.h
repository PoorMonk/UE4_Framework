// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DecActor.generated.h"

class ASrcActor;

UCLASS()
class FRAMECOURSE_API ADecActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADecActor();

	void ReflectInstance();

	void ControlUProperty();
	//void ControlUFunction();

	//调用UFuntion方法一： FScriptDelegate
	void RunUFunOne();

	//调用UFuntion方法二： FBaseDelegate
	void RunUFunTwo();

	//调用UFuntion方法三： UFuntion
	void RunUFunThree();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	ASrcActor* SrcActor;
	UObject* SrcObj;
};
