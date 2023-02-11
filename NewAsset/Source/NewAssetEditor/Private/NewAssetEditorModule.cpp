#include "Modules/ModuleManager.h"
#include "IAssetTypeActions.h"


class FNewAssetEditorModule : public IModuleInterface
{
	TSharedPtr<IAssetTypeActions> Action;

	virtual void StartupModule() override
	{
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
			Action = MakeShareable(new FNewAssetAction());
		AssetTools.RegisterAssetTypeActions(Action.ToSharedRef());
	}
	virtual void ShutdownModule() override
	{
		FAssetToolsModule* Module = FModuleManager::GetModulePtr<FAssetToolsModule>("AssetTools");
		if (Module)
		{
			IAssetTools& AssetTools = Module->Get();
			if (Action.IsValid())
			{
				AssetTools.UnregisterAssetTypeActions(Action.ToSharedRef());
			}
		}
	}


};

IMPLEMENT_MODULE(FNewAssetEditorModule,NewAssetEditor)