// Fill out your copyright notice in the Description page of Project Settings.


#include "FrameworkCharacter.h"
#include "Engine/GameEngine.h"

// Sets default values
AFrameworkCharacter::AFrameworkCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFrameworkCharacter::FCDebug(FString Message, int32 iValue)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, Message + " " + FString::FromInt(iValue));
	}
}

#if WITH_EDITOR
void AFrameworkCharacter::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(AFrameworkCharacter, AcSix))
	{
		id += 10;
	}
}
#endif

// Called when the game starts or when spawned
void AFrameworkCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFrameworkCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFrameworkCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

