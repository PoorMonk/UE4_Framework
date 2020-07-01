// Fill out your copyright notice in the Description page of Project Settings.


#include "DecActor.h"
#include "ReflectObject.h"
#include "FCommonObject.h"
#include "UObjectGlobals.h"
#include "Engine/Blueprint.h"
#include "SrcActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADecActor::ADecActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADecActor::ReflectInstance()
{
	UClass* RefObjClass = StaticLoadClass(UObject::StaticClass(), nullptr, TEXT("UReflectObject"));
	UReflectObject* RefObjIns = Cast<UReflectObject>(RefObjClass);
	//RefObjIns->EchoInfo();

	UObject* RefObjPtr = StaticLoadObject(UObject::StaticClass(), nullptr, TEXT("UReflectObject"));
	UReflectObject* RefObjOth = Cast<UReflectObject>(RefObjPtr);
	//RefObjOth->EchoInfo();

	/*if (RefObjIns == RefObjPtr)
	{
		FHelper::Debug("Is Same", 15.f);
	}*/

	//反射Enum
	UEnum* EnumPtr = FindObject<UEnum>((UObject*)ANY_PACKAGE, *FString("ERefState"), true);
	//FHelper::Debug(EnumPtr->GetEnumName((int32)1));

	//反射生成对象
	UBlueprint* RefActorBP = LoadObject<UBlueprint>(nullptr, TEXT("Blueprint'/Game/Blueprints/Reflect/BP_Actor.BP_Actor'"));
	TSubclassOf<AActor> RefActorClass = (UClass*)RefActorBP->GeneratedClass;
	GetWorld()->SpawnActor<AActor>(RefActorClass, FVector::ZeroVector + FVector(0.f, 0.f, 60.f), FRotator::ZeroRotator);
}

void ADecActor::ControlUProperty()
{
	for (TFieldIterator<UProperty> ProIt(SrcObj->GetClass()); ProIt; ++ProIt)
	{
		UProperty* Property = *ProIt;
		if (Property->GetNameCPP().Equals("ActorName"))
		{
			UStrProperty* StrProperty = Cast<UStrProperty>(Property);
			if (StrProperty)
			{
				void* ValPtr = Property->ContainerPtrToValuePtr<uint8*>(SrcObj);
				FHelper::Debug(FString("ActorName Before --> ") + StrProperty->GetPropertyValue(ValPtr));
				StrProperty->SetPropertyValue(ValPtr, FString("Harkey"));

			}
			FHelper::Debug(FString("ActorName After --> ") + SrcActor->ActorName);
		}
		else if (Property->GetNameCPP().Equals("IsActive"))
		{
			UBoolProperty* BoolProperty = Cast<UBoolProperty>(Property);
			if (BoolProperty)
			{
				void* ValuePtr = Property->ContainerPtrToValuePtr<uint8*>(SrcObj);
				FHelper::Debug(FString("IsActive Before --> ") + FString::FromInt(BoolProperty->GetPropertyValue(ValuePtr)));
				BoolProperty->SetPropertyValue(ValuePtr, false);
			}
			FHelper::Debug(FString("IsActive After --> ") + FString::FromInt(SrcActor->IsActive));
		}
	}
}

void ADecActor::RunUFunOne()
{
	FScriptDelegate FunDelOne;
	FunDelOne.BindUFunction(SrcObj, FName("UFunOne"));
	//FunDelOne.ProcessDelegate<UObject>(nullptr);

	FScriptDelegate FunDelTwo;
	FunDelTwo.BindUFunction(SrcObj, FName("UFunTwo"));
	struct 
	{
		FString InfoStr;
		int32 Count;
	} FunTwoParams;
	FunTwoParams.InfoStr = FString("ASrcActor --> UFunTwo");
	FunTwoParams.Count = 567;
	FunDelTwo.ProcessDelegate<UObject>(&FunTwoParams);
	FHelper::Debug(FString::FromInt(FunTwoParams.Count));

}

void ADecActor::RunUFunTwo()
{
	// TBaseDelegate参数没法传引用
	TBaseDelegate<bool, FString, int32> FunDelThree = TBaseDelegate<bool, FString, int32>::CreateUFunction(SrcObj, "UFunThree");
	bool DelResult = FunDelThree.Execute(FString("ASrcActor --> UFunThree"), 789);
	if (DelResult) FHelper::Debug("Return True");
}

void ADecActor::RunUFunThree()
{
	UFunction* FunFour = SrcObj->FindFunction(FName("UFunFour"));
	if (FunFour)
	{
		struct 
		{
			FString InfoStr;
			int32 Count;
		} FunFourParams;
		FunFourParams.InfoStr = FString("ASrcActor --> UFunFour");
		FunFourParams.Count = 675;
		SrcObj->ProcessEvent(FunFour, &FunFourParams);

		uint8* RetValPtr = (uint8*)&FunFourParams + FunFour->ReturnValueOffset;
		int32* RetVal = (int32*)RetValPtr;
		FHelper::Debug(FString("Return Value --> ") + FString::FromInt(*RetVal));
		FHelper::Debug(FString("Count Value --> ") + FString::FromInt(FunFourParams.Count));
	}
}

// Called when the game starts or when spawned
void ADecActor::BeginPlay()
{
	Super::BeginPlay();
	//ReflectInstance();

	TArray<AActor*> ActArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASrcActor::StaticClass(), ActArray);
	if (ActArray.Num() > 0)
	{
		SrcActor = Cast<ASrcActor>(ActArray[0]);
		SrcObj = (UObject*)SrcActor;

		//ControlUProperty();
		//RunUFunOne();
		//RunUFunTwo();
		//RunUFunThree();
	}
}

// Called every frame
void ADecActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

