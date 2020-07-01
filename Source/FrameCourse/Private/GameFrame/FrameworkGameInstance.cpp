// Fill out your copyright notice in the Description page of Project Settings.


#include "FrameworkGameInstance.h"
#include "Engine/GameEngine.h"
#include "Kismet/GameplayStatics.h"
#include "FrameworkCharacter.h"

void UFrameworkGameInstance::FGIDebug(FString Message, int32 iValue)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, Message + " " + FString::FromInt(iValue));
	}
}

bool UFrameworkGameInstance::ProcessConsoleExec(const TCHAR* Cmd, FOutputDevice& Ar, UObject* Executor)
{
	bool Res = Super::ProcessConsoleExec(Cmd, Ar, Executor);

	if (!Res)
	{
		TArray<AActor*> Actors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFrameworkCharacter::StaticClass(), Actors);
		for (auto actor : Actors)
		{
			Res = actor->ProcessConsoleExec(Cmd, Ar, Executor);
		}
	}

	return Res;
}
