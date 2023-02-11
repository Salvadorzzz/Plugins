#include "NewAssetAction.h"
#include "NewAsset.h"


FText FNewAssetAction::GetName() const
{
	return FText::FromString(GetSupportedClass()->GetName());
}

FColor FNewAssetAction::GetTypeColor() const
{
	return FColor::Red;
}

UClass* FNewAssetAction::GetSupportedClass() const
{
	return UNewAsset::StaticClass();
}

uint32 FNewAssetAction::GetCategories()
{
	return EAssetTypeCategories::Basic;
}

