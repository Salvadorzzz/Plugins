// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyBlankPlugin.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "MyBlankPluginStyle.h"
#include "MyBlankPluginCommands.h"
#include "LevelEditor.h"
#include "IAnimationBlueprintEditorModule.h"

#define LOCTEXT_NAMESPACE "FMyBlankPluginModule"

void FMyBlankPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FMyBlankPluginStyle::Initialize();
	FMyBlankPluginStyle::ReloadTextures();
	FMyBlankPluginCommands::Register();

	//创建一个共享的指针，指向一个使用 MakeShareable 函数的命令列表
	PluginCommands = MakeShareable(new FUICommandList);
	//使用MapAction为FMyBlankPluginCommands 成员的 UICommandInfo 对象和调用命令时要执行的实际函数之间创建映射或关联
	PluginCommands->MapAction(FMyBlankPluginCommands::Get().PluginAction, FExecuteAction::CreateRaw(this, &FMyBlankPluginModule::PluginButtonClicked), FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FMyBlankPluginModule::RegisterMenu));


}

void FMyBlankPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	UToolMenus::UnRegisterStartupCallback(this);
	UToolMenus::UnregisterOwner(this);
	FMyBlankPluginStyle::Shutdown();
	FMyBlankPluginCommands::Unregister();
}

void FMyBlankPluginModule::PluginButtonClicked()
{
	FText DialogText = FText::FromString("Hi, this is a BlankPlugin content");
	FMessageDialog::Open(EAppMsgType ::Ok, DialogText);
}

void FMyBlankPluginModule::RegisterMenu()
{
	{
		/////////////////////////////////////////AddToolBarButtonWithNewSection_Begin
		{
			UToolMenu* ToolBarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
			{
				FToolMenuSection& ToolBarMenuSection = ToolBarMenu->FindOrAddSection("ToolBarMenuSection");
				FToolMenuEntry& ToolBarMenuEntry = ToolBarMenuSection.AddEntry(FToolMenuEntry::InitToolBarButton(FMyBlankPluginCommands::Get().PluginAction));
				ToolBarMenuEntry.SetCommandList(PluginCommands);

			}
		}
		/////////////////////////////////////////AddToolBarButtonWithNewSection_End

		/////////////////////////////////////////AddToolBarButtonInContentSection_Begin
		{
			UToolMenu* ToolBarMenu1 = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.AssetsToolBar");
			{
				FToolMenuSection& ToolBarMenuSection1 = ToolBarMenu1->FindOrAddSection("Content");
				FToolMenuEntry& ToolBarMenuEntry1 = ToolBarMenuSection1.AddEntry(FToolMenuEntry::InitToolBarButton(FMyBlankPluginCommands::Get().PluginAction));
				ToolBarMenuEntry1.SetCommandList(PluginCommands);
				//更改UI排列顺序
				//ToolBarMenuEntry1.InsertPosition.Position = EToolMenuInsertType::First;
			}
		}
		/////////////////////////////////////////AddToolBarButtonInContentSection_End

			/////////////////////////////////////////AddToolBarButtonInFileSection_Begin
		{
			UToolMenu* ToolBarMenu2 = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.ModesToolBar");
			{
				FToolMenuSection& ToolBarMenuSection2 = ToolBarMenu2->FindOrAddSection("File");
				FToolMenuEntry& ToolBarMenuEntry2 = ToolBarMenuSection2.AddEntry(FToolMenuEntry::InitToolBarButton(FMyBlankPluginCommands::Get().PluginAction));
				ToolBarMenuEntry2.SetCommandList(PluginCommands);
			}
		}
		/////////////////////////////////////////AddToolBarButtonInFileSection_End

		/////////////////////////////////////////AddToolBarButtonInEditorModesSection_Begin
		{
			UToolMenu* ToolBarMenu3 = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.ModesToolBar");
			{
				//需要输入一个与EditorModes不同名字的Sectoin，如果相同，它不会创建，创建成功的话会在Select Mode 框后面创建
				FToolMenuSection& ToolBarMenuSection3 = ToolBarMenu3->AddSection("EditorModes1");
				FToolMenuEntry& ToolBarMenuEntry3 = ToolBarMenuSection3.AddEntry(FToolMenuEntry::InitToolBarButton(FMyBlankPluginCommands::Get().PluginAction));
				ToolBarMenuEntry3.SetCommandList(PluginCommands);
			}
		}
		/////////////////////////////////////////AddToolBarButtonInEditorModesSection_End

		/////////////////////////////////////////AddToolBarButtonInPlaySection_Begin
		{
			UToolMenu* ToolBarMenu4 = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
			{
				FToolMenuSection& ToolBarMenuSection4 = ToolBarMenu4->FindOrAddSection("Play");
				FToolMenuEntry& ToolBarMenuEntry4 = ToolBarMenuSection4.AddEntry(FToolMenuEntry::InitToolBarButton(FMyBlankPluginCommands::Get().PluginAction));
				ToolBarMenuEntry4.SetCommandList(PluginCommands);

			}
		}
		/////////////////////////////////////////AddToolBarButtonInPlaySection_End





	/////////////////////////////////////////AddMainMenuButtonInFile_Begin
	{
		UToolMenu* MainMenuFileButton = UToolMenus::Get()->ExtendMenu("MainFrame.MainMenu.File");
		{
			FToolMenuSection& MainMenuSection = MainMenuFileButton->FindOrAddSection("FileOpen");
			MainMenuSection.AddMenuEntryWithCommandList(FMyBlankPluginCommands::Get().PluginAction, PluginCommands);
		}
	}
	/////////////////////////////////////////AddMainMenuButtonInFile_End

	{
		/////////////////////////////////////////Create New MainMenu
		UToolMenus* NewMenu = UToolMenus::Get();
		UToolMenu* MyNewMenu = NewMenu->RegisterMenu("MainFrame.MainMenu.NewMenu");
		FToolMenuSection& NewMenuSection = MyNewMenu->AddSection("NewSection");
		NewMenuSection.AddMenuEntryWithCommandList(FMyBlankPluginCommands::Get().PluginAction, PluginCommands);
		UToolMenu* MenuBar = UToolMenus::Get()->ExtendMenu("MainFrame.MainMenu");
		MenuBar->AddSubMenu(
			"MainMenu",
			"NewSection",
			"NewMenu",
			LOCTEXT("MyMenu", "My")
		);

	}
	}
	/////////////////////////////////////////Old way to create menu

	{
	/////////////////////////////////////////Create a Button in AnimationBlueprintEditor-Help-HelpApplication_Begin
	// //在动画蓝图的下拉菜单中的某一个Section中添加一个按钮
	//创建一个扩展器的智能指针
	Extender = MakeShareable(new FExtender());
	IAnimationBlueprintEditorModule& AnimationBlueprintEditorModule = FModuleManager::LoadModuleChecked<IAnimationBlueprintEditorModule>("AnimationBlueprintEditor");

	//对该扩展器增加一个扩展（对扩展行为的包装） 在哪儿附近进行扩展；扩展的位置；命令集；构造一个委托；绑定一个函数
	Extender->AddMenuExtension("HelpApplication", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FMyBlankPluginModule::AddMenuExtension));

	//拿到扩展管理器，增加扩展
	AnimationBlueprintEditorModule.GetMenuExtensibilityManager()->AddExtender(Extender);

	/////////////////////////////////////////Create a Button in AnimationBlueprintEditor-Help-HelpApplication_End
	}

	{
	/////////////////////////////////////////Create a Button in AnimationBlueprintEditor_Begin
	//在动画蓝图的菜单栏添加一个按钮
		//创建一个扩展器的智能指针
	AnimToolBarExtender = MakeShareable(new FExtender());
	IAnimationBlueprintEditorModule& AnimationBlueprintEditorModule = FModuleManager::LoadModuleChecked<IAnimationBlueprintEditorModule>("AnimationBlueprintEditor");

	//对该扩展器增加一个扩展（对扩展行为的包装） 在哪儿附近进行扩展；扩展的位置；命令集；构造一个委托；绑定一个函数
	AnimToolBarExtender->AddMenuBarExtension("Help", EExtensionHook::Before, PluginCommands, FMenuBarExtensionDelegate::CreateRaw(this, &FMyBlankPluginModule::AddMenuBarExtension));

	//拿到扩展管理器，增加扩展
	AnimationBlueprintEditorModule.GetMenuExtensibilityManager()->AddExtender(AnimToolBarExtender);

	/////////////////////////////////////////Create a Button in AnimationBlueprintEditor_End
	}


	{
	/////////////////////////////////////////Create a Button on Settings bar in AnimationBlueprintEditor_Begin
	//在动画蓝图的菜单栏的设置栏添加一个按钮

	MenuBarExtender = MakeShareable(new FExtender());
	IAnimationBlueprintEditorModule& AnimationBlueprintEditorModule = FModuleManager::LoadModuleChecked<IAnimationBlueprintEditorModule>("AnimationBlueprintEditor");

	MenuBarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FMyBlankPluginModule::AddToolBarExtension));

	AnimationBlueprintEditorModule.GetToolBarExtensibilityManager()->AddExtender(MenuBarExtender);

	/////////////////////////////////////////Create a Button on Settings bar in AnimationBlueprintEditor_End
	}


	{
		//FBlueprintEditorModule& BlueprintEditorModule = FModuleManager::LoadModuleChecked < FBlueprintEditorModule >("Kismet");
		//BlueprintEditorModule.OnRegisterTabsForEditor().AddRaw(this, &FMyBlankPluginModule::OnBPToolBarRegister);
	}






}

void FMyBlankPluginModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.BeginSection(TEXT("MyButton"));
	Builder.AddMenuEntry(FMyBlankPluginCommands::Get().PluginAction);
	Builder.EndSection();
}

void FMyBlankPluginModule::AddMenuBarExtension(FMenuBarBuilder& Builder)
{
	Builder.AddMenuEntry(FMyBlankPluginCommands::Get().PluginAction);
}

void FMyBlankPluginModule::AddToolBarExtension(FToolBarBuilder& Builder)
{
	Builder.BeginSection(TEXT("MyButton"));
	Builder.AddToolBarButton(FMyBlankPluginCommands::Get().PluginAction);
	Builder.EndSection();
}

void FMyBlankPluginModule::OnBPToolBarRegister(class FWorkflowAllowedTabSet& TabSet, FName Name, TSharedPtr<FBlueprintEditor> BP)
{
	ToolBarExtender = MakeShareable(new FExtender);
	ToolBarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FMyBlankPluginModule::AddToolBarExtension));
	BP->AddToolbarExtender(ToolBarExtender);

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMyBlankPluginModule, MyBlankPlugin)