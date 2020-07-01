// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FrameworkCharacter.generated.h"

UCLASS()
class FRAMECOURSE_API AFrameworkCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFrameworkCharacter();

	UFUNCTION(Exec, Category = "Framework")
		void FCDebug(FString Message, int32 iValue);

#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Framework")
		AActor* AcOne;	//场景中实际存在的对象指针

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Framework")
		TSubclassOf<AActor> AcTwo;	//对象的类的类型，允许使用类型安全传递UClass的模板

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Framework")
		TSoftObjectPtr<AActor> AcThree;	//对象的软引用，需要的时候再加载

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Framework")
		TSoftClassPtr<AActor> AcFour;	//对象的类的类型的软引用，需要的时候再加载

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Framework")
		TAssetPtr<AActor> AcFive;	//资源引用，是对FStringAssetReference的封装，包含对象路径与弱指针

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Framework")
		FStringAssetReference AcSix;	//资源路径的引用

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "AllowEidt"), Category = "Framework")
		bool bAllow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 10, ClampMax = 30, EditCondition = bAllow), Category = "Framework")
		int32 id;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
