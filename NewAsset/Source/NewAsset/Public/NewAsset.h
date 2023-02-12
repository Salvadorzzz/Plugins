// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IDetailCustomization.h"
#include "DetailLayoutBuilder.h"
#include "NewAsset.generated.h"


UCLASS(BlueprintType,Blueprintable)
class NEWASSET_API UNewAsset : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=NewAsset)
	int Score;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = NewAsset)
	UStaticMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = NewAsset)
	float a;

	UFUNCTION(BlueprintCallable)
	void CalScore();

};
