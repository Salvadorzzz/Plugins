// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyEditorStandaloneWindow.h"
#include "MyEditorStandaloneWindowStyle.h"
#include "MyEditorStandaloneWindowCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"
#include "SMySlate.h"

static const FName MyEditorStandaloneWindowTabName("MyEditorStandaloneWindow");

#define LOCTEXT_NAMESPACE "FMyEditorStandaloneWindowModule"

void FMyEditorStandaloneWindowModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FMyEditorStandaloneWindowStyle::Initialize();
	FMyEditorStandaloneWindowStyle::ReloadTextures();

	FMyEditorStandaloneWindowCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FMyEditorStandaloneWindowCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FMyEditorStandaloneWindowModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FMyEditorStandaloneWindowModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(MyEditorStandaloneWindowTabName, FOnSpawnTab::CreateRaw(this, &FMyEditorStandaloneWindowModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FMyEditorStandaloneWindowTabTitle", "MyEditorStandaloneWindow"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FMyEditorStandaloneWindowModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FMyEditorStandaloneWindowStyle::Shutdown();

	FMyEditorStandaloneWindowCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(MyEditorStandaloneWindowTabName);
}

TSharedRef<SDockTab> FMyEditorStandaloneWindowModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FMyEditorStandaloneWindowModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("MyEditorStandaloneWindow.cpp"))
		);
	TSharedPtr<SMySlate> SlateWidget;

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SAssignNew(SlateWidget, SMySlate)   //Create custom widget
			.IsFocusable(true)                                //Initialize custom parameters
		.OnMyClicked(FOnButtonClicked::CreateRaw(this, &FMyEditorStandaloneWindowModule::OnClickButton))
		];
}

void FMyEditorStandaloneWindowModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(MyEditorStandaloneWindowTabName);
}

FReply FMyEditorStandaloneWindowModule::OnClickButton()
{
	UE_LOG(LogTemp, Log, TEXT("Bind Fcuntion!"));
	return FReply::Handled();
}

void FMyEditorStandaloneWindowModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

// 	{
// 		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
// 		{
// 			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
// 			Section.AddMenuEntryWithCommandList(FMyEditorStandaloneWindowCommands::Get().OpenPluginWindow, PluginCommands);
// 		}
// 	}
// 
// 	{
// 		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
// 		{
// 			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
// 			{
// 				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FMyEditorStandaloneWindowCommands::Get().OpenPluginWindow));
// 				Entry.SetCommandList(PluginCommands);
// 			}
// 		}
// 	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMyEditorStandaloneWindowModule, MyEditorStandaloneWindow)