// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/StreamableManager.h"
#include "AsynClassActor.generated.h"

struct FStreamableHandle;
struct FStreamableManager;

UCLASS()
class FRAMECOURSE_API AAsynClassActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAsynClassActor();

	void LoadWealthCompleted();

public:
	UPROPERTY(EditAnywhere)
		TArray<TSoftClassPtr<UObject>> ClassWealthPaths;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	TSharedPtr<FStreamableHandle> WealthHandle;
	FStreamableManager WealthLoader;
	TArray<AActor*> WealthActors;

	float TimeCounter;
	int32 IndexCounter;
};
