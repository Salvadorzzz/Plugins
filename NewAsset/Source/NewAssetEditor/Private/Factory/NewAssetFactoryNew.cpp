#include "NewAssetFactoryNew.h"
#include "NewAsset.h"


UNewAssetFactoryNew::UNewAssetFactoryNew(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	SupportedClass = UNewAsset::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UNewAssetFactoryNew::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	return NewObject<UNewAsset>(InParent, InClass, InName, Flags);
}

bool UNewAssetFactoryNew::ShouldShowInNewMenu() const
{
	return true;
}
