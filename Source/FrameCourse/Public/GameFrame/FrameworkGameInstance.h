// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FrameworkGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class FRAMECOURSE_API UFrameworkGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UFUNCTION(Exec, Category = "Framework")
		void FGIDebug(FString Message, int32 iValue);

	virtual bool ProcessConsoleExec(const TCHAR* Cmd, FOutputDevice& Ar, UObject* Executor) override;

};
