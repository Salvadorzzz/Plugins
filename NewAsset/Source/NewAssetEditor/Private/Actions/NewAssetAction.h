#pragma once

#include "AssetTypeActions_Base.h"

class FNewAssetAction : public FAssetTypeActions_Base
{
public :
	FText GetName() const override;
	FColor GetTypeColor() const override;
	UClass* GetSupportedClass() const override;
	uint32 GetCategories() override;
};