// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NewAsset.generated.h"

/**
 * 
 */
UCLASS()
//This is custom Object type
class NEWASSET_API UNewAsset : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnyWhere,BlueprintReadOnly, Category=NewAsset)
	int32 IntValue;

	UFUNCTION(BlueprintCallable)
	void IntFunc();
};
