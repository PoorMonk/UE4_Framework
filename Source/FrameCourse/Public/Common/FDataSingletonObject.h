// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FDataSingletonObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class FRAMECOURSE_API UFDataSingletonObject : public UObject
{
	GENERATED_BODY()
	
public:
	UFDataSingletonObject();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Framework")
		TArray<UClass*> SourceBlueprints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Framework")
		class UTexture2D* SourceT2D;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Framework")
		FVector SourceVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Framework")
		FString SourceFilePath;

};
