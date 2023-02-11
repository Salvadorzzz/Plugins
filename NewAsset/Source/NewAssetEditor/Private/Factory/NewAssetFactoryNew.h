#pragma  once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "NewAssetFactoryNew.generated.h"

UCLASS()
class  UNewAssetFactoryNew : public UFactory
{
	GENERATED_UCLASS_BODY()

public:
	//Create NewAsset in right click in content browser
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	virtual bool ShouldShowInNewMenu() const override;

	//drag a NewAsset in Resource Manager
	virtual UObject* FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled);
};