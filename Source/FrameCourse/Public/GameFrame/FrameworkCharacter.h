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
		AActor* AcOne;	//������ʵ�ʴ��ڵĶ���ָ��

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Framework")
		TSubclassOf<AActor> AcTwo;	//�����������ͣ�����ʹ�����Ͱ�ȫ����UClass��ģ��

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Framework")
		TSoftObjectPtr<AActor> AcThree;	//����������ã���Ҫ��ʱ���ټ���

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Framework")
		TSoftClassPtr<AActor> AcFour;	//�����������͵������ã���Ҫ��ʱ���ټ���

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Framework")
		TAssetPtr<AActor> AcFive;	//��Դ���ã��Ƕ�FStringAssetReference�ķ�װ����������·������ָ��

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Framework")
		FStringAssetReference AcSix;	//��Դ·��������

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
