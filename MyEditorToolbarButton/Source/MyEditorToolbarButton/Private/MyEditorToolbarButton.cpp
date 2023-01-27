// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyEditorToolbarButton.h"
#include "MyEditorToolbarButtonStyle.h"
#include "MyEditorToolbarButtonCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "AnimationBlueprintEditor/Public/IAnimationBlueprintEditorModule.h"
#include "LevelEditorActions.h"

static const FName MyEditorToolbarButtonTabName("MyEditorToolbarButton");

#define LOCTEXT_NAMESPACE "FMyEditorToolbarButtonModule"

void FMyEditorToolbarButtonModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FMyEditorToolbarButtonStyle::Initialize();
	FMyEditorToolbarButtonStyle::ReloadTextures();

	FMyEditorToolbarButtonCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FMyEditorToolbarButtonCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FMyEditorToolbarButtonModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FMyEditorToolbarButtonModule::RegisterMenus));
}

void FMyEditorToolbarButtonModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FMyEditorToolbarButtonStyle::Shutdown();

	FMyEditorToolbarButtonCommands::Unregister();
}

void FMyEditorToolbarButtonModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FMyEditorToolbarButtonModule::PluginButtonClicked()")),
							FText::FromString(TEXT("MyEditorToolbarButton.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FMyEditorToolbarButtonModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	//{
	//	UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
	//	{
	//		FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
	//		Section.AddMenuEntryWithCommandList(FMyEditorToolbarButtonCommands::Get().PluginAction, PluginCommands);
	//	}
	//}

	//{
	//	UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
	//	{
	//		FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
	//		{
	//			FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FMyEditorToolbarButtonCommands::Get().PluginAction));
	//			Entry.SetCommandList(PluginCommands);
	//		}
	//	}

	//	//Add a new button in ToolBar
	//	UToolMenu* ToolBarMenu2 = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
	//	{
	//		FToolMenuSection& Section = ToolBarMenu2->FindOrAddSection("PluginTools2");
	//		FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FMyEditorToolbarButtonCommands::Get().PluginAction));
	//		Entry.SetCommandList(PluginCommands);
	//	}

		//UToolMenus* ToolBarMenu3= UToolMenus::Get();
		//{
		//	UToolMenu* MyMenu= ToolBarMenu3->RegisterMenu("LevelEditor.MainMenu.MySubMenu");
		//	FToolMenuSection& Section1 = MyMenu->AddSection("PluginTools3");
		//	Section1.AddMenuEntryWithCommandList(FMyEditorToolbarButtonCommands::Get().PluginAction, PluginCommands);
		//	UToolMenu* MenuBar = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu");
		//	MenuBar->AddSubMenu(
		//		"MainMenu",
		//		"PluginTools3",
		//		"MySubMenu",
		//		LOCTEXT("MyMenu", "My")
		//	);


			////�Ϸ���
			//IAnimationBlueprintEditorModule& AnimationBlueprintEditorModule = FModuleManager::LoadModuleChecked<IAnimationBlueprintEditorModule>("AnimationBlueprintEditor");
			////����һ���༭��ģ�������                                                                                    ģ�����������ģ��                                  ģ�������                                        ģ���������� �����
			//TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender);
			////����һ����չ������Ϊ����Ҫ�Դ��ڽ�����չ
			//MenuExtender->AddMenuExtension("HelpApplication", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this,&FMyEditorToolbarButtonModule::AddMenuExtension));
		 //   //���������︽����չ����ǰ�滹�Ǻ���;�����һ��ʼ��ʱ��������˵�һ��������������һ��ί�У���һ������
			//AnimationBlueprintEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
			////����չ���ӵ�������չ��������������ȥ

			/////��δ���û����Ч ��ʱ��֪��Ϊʲô
	//}
}

void FMyEditorToolbarButtonModule::AddMenuExtension(class FMenuBuilder& Builder)
{
	Builder.BeginSection(TEXT("MyButton"));
	Builder.AddMenuEntry(FMyEditorToolbarButtonCommands::Get().PluginAction);
	Builder.EndSection();
}

void FMyEditorToolbarButtonModule::AddToolBarExtension(class FToolBarBuilder& Builder)
{
	Builder.BeginSection(TEXT("MyButton"));
	Builder.AddToolBarButton(FMyEditorToolbarButtonCommands::Get().PluginAction);
	Builder.EndSection();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMyEditorToolbarButtonModule, MyEditorToolbarButton)