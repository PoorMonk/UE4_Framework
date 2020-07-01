#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "FCallInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint) )
class UFCallInterface : public UInterface
{
	GENERATED_BODY()
	//GENERATED_UINTERFACE_BODY()
};

/**
 * 
 */
class FRAMECOURSE_API IFCallInterface
{
	GENERATED_BODY()
	//GENERATED_UINTERFACE_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, Category = "Framewrok")
		virtual void FCallFun(const FString& HitResult) = 0;
};
