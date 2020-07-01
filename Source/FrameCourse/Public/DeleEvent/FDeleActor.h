// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FDeleActor.generated.h"

DECLARE_DELEGATE(FDE_Single_Zero)
DECLARE_DELEGATE_TwoParams(FDE_Single_Two, FString, int32)
DECLARE_MULTICAST_DELEGATE(FDE_Multi_Zero)

//��̬ί��������ʱ��Ҫ�ӷֺţ�
DECLARE_DYNAMIC_DELEGATE(FDE_Dy_S_Zero);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDE_Dy_M_One, FString, InfoStr); //FString��ʾ�������ͣ�InfoStr��ʾ��������

UCLASS()
class FRAMECOURSE_API AFDeleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFDeleActor();

	UFUNCTION(BlueprintCallable, Category = "Framework")
		void RegFunDele(FDE_Dy_S_Zero TargetFun);
	
	//TFunction���ݺ���
	void RegFunOne(TFunction<void(FString)> TargetFun);
	
	//TMemFunPtrType���ݺ���
	template<class UserClass>
	void RegFunTwo(UserClass* TarObj, typename TMemFunPtrType<false, UserClass, void(FString, int32)>::Type InMethod);
	
	//FMethodPtr���ݺ���
	template<class UserClass>
	void RegFunThree(UserClass* TarObj, typename FDE_Single_Two::TUObjectMethodDelegate<UserClass>::FMethodPtr InMethod);

	//���Ͷ���ͳһ�ӿ�
	template<class DelegateType, class UserClass, typename... VarTypes>
	void RegFunFour(UserClass* TarObj, typename DelegateType::template TUObjectMethodDelegate<UserClass>::FMethodPtr InMethod, VarTypes... Vars);

	template<typename RetType, typename... VarTypes>
	void RegFunFive(TFunction<RetType(VarTypes...)> TarFun);

public:
	//ί�в�����BlueprintAssignable��ʾ������ͼ�и�ֵ(ֻ�ж�̬�ಥί�п������˱�ʶ��)
	UPROPERTY(BlueprintAssignable, Category = "Framework")
		FDE_Dy_M_One FDSZFun;

	//UPROPERTY(BlueprintAssignable, Category = "Framework")
	//	FDE_Multi_Zero FDSZFunTwo;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	TFunction<void(FString)> TFunOne;

};

//��cpp�ļ��лᱨ���Ӵ���
template<class UserClass>
void AFDeleActor::RegFunTwo(UserClass* TarObj, typename TMemFunPtrType<false, UserClass, void(FString, int32)>::Type InMethod)
{
	FDE_Single_Zero ExeDele;
	ExeDele.BindUObject(TarObj, InMethod, FString("haha"), 54);
	ExeDele.ExecuteIfBound();
}

template<class UserClass>
void AFDeleActor::RegFunThree(UserClass* TarObj, typename FDE_Single_Two::TUObjectMethodDelegate<UserClass>::FMethodPtr InMethod)
{
	FDE_Single_Two ExeDele;
	ExeDele.BindUObject(TarObj, InMethod);
	ExeDele.ExecuteIfBound(FString("Harkey"), 28);
}

template<class DelegateType, class UserClass, typename... VarTypes>
void AFDeleActor::RegFunFour(UserClass* TarObj, typename DelegateType::template TUObjectMethodDelegate<UserClass>::FMethodPtr InMethod, VarTypes... Vars)
{
	FDE_Single_Zero ExeDele;
	ExeDele.BindUObject(TarObj, InMethod, Vars...);
	ExeDele.ExecuteIfBound();
}

template<typename RetType, typename... VarTypes>
void AFDeleActor::RegFunFive(TFunction<RetType(VarTypes...)> TarFun)
{
	if (TarFun(FString("RegFunFive"), 24))
	{
		//FHelper::Debug(FString("True"), 10.f);
	}
}
