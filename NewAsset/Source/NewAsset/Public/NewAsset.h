// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NewAsset.generated.h"


UCLASS(BlueprintType,Blueprintable)
class NEWASSET_API UNewAsset : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=NewAsset)
	float Score=0.f;

	UFUNCTION(BlueprintCallable)
	void CalScore();
};
