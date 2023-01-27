// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyBlankPluginStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Framework/Application/SlateApplication.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FMyBlankPluginStyle::StyleInstance = nullptr;

void FMyBlankPluginStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FMyBlankPluginStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FMyBlankPluginStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("MyBlankPluginStyle"));
	return StyleSetName;
}

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FMyBlankPluginStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("MyBlankPluginStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("MyBlankPlugin")->GetBaseDir() / TEXT("Resources"));

	Style->Set("MyBlankPlugin.PluginAction", new IMAGE_BRUSH_SVG(TEXT("save_d"), Icon20x20));

	return Style;
}

void FMyBlankPluginStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FMyBlankPluginStyle::Get()
{
	return *StyleInstance;
}
