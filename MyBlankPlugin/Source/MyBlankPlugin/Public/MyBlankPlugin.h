// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"
#include "BlueprintEditor.h"

class FMyBlankPluginModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** This function will be bound to Command. */
	void PluginButtonClicked();

private:
	void RegisterMenu();

	void AddMenuExtension(FMenuBuilder& Builder);

	void AddMenuBarExtension(FMenuBarBuilder& Builder);

	void AddToolBarExtension(FToolBarBuilder& Builder);

	void OnBPToolBarRegister(class FWorkflowAllowedTabSet& TabSet,FName Name,TSharedPtr<FBlueprintEditor> BP);





private:

	TSharedPtr<class FUICommandList> PluginCommands;

	TSharedPtr< FExtender> Extender;
	TSharedPtr< FExtender > AnimToolBarExtender;
	TSharedPtr< FExtender> MenuBarExtender;
	TSharedPtr< FExtender> ToolBarExtender;

};
