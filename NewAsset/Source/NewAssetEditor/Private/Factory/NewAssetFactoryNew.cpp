#include "NewAssetFactoryNew.h"
#include "NewAsset.h"
#include "Misc/FileHelper.h"


UNewAssetFactoryNew::UNewAssetFactoryNew(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	SupportedClass = UNewAsset::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;

	//drag a NewAsset in Resource Manager
	//Specify a suffix
// 	Formats.Add(FString(TEXT("myfile;'")));
// 	SupportedClass = UNewAsset::StaticClass();
// 	bCreateNew = false;
// 	bEditorImport = true;
}

UObject* UNewAssetFactoryNew::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	return NewObject<UNewAsset>(InParent, InClass, InName, Flags);
}

bool UNewAssetFactoryNew::ShouldShowInNewMenu() const
{
	return true;
}

UObject* UNewAssetFactoryNew::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	UNewAsset* NewAsset = nullptr;
	TArray<uint8> Bytes;

	if (FFileHelper::LoadFileToArray(Bytes, *Filename) && Bytes.Num() >= sizeof(int32))
	{
		NewAsset = NewObject<UNewAsset>(InParent, InClass, InName, Flags);
		for (uint32 i = 0; i < sizeof(int32); ++i)
		{
			NewAsset->Score |= Bytes[i] << (i * 8);

		}
	}

	bOutOperationCanceled = false;
	
	return NewAsset;
}
