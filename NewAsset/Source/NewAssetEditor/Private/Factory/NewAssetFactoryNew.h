#pragma  once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "NewAssetFactoryNew.generated.h"

UCLASS()
class  UNewAssetFactoryNew : public UFactory
{
	GENERATED_UCLASS_BODY()

public:
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	virtual bool ShouldShowInNewMenu() const override;
};