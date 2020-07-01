// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UFInterface : public UInterface
{
	GENERATED_BODY()

	//GENERATED_UINTERFACE_BODY()
};

/**
 * 
 */
class FRAMECOURSE_API IFInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Framework")
		void FFunOne(const FString& HitResult);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Framework")
		void FFunTwo(const FString& HitResult);

	UFUNCTION(BlueprintNativeEvent, Category = "Framework")
		void FFunThree(const FString& HitResult);

	UFUNCTION(BlueprintImplementableEvent, Category = "Framework")
		void FFunFour(const FString& HitResult);

	//不能单独使用BlueprintCallable属性
	/*UFUNCTION(BlueprintCallable, Category = "Framework")
		virtual void FFunFive(const FString& HitResult);*/
};
