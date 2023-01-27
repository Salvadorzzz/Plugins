// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyEditorToolbarButtonStyle.h"
#include "MyEditorToolbarButton.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FMyEditorToolbarButtonStyle::StyleInstance = nullptr;

void FMyEditorToolbarButtonStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FMyEditorToolbarButtonStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FMyEditorToolbarButtonStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("MyEditorToolbarButtonStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FMyEditorToolbarButtonStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("MyEditorToolbarButtonStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("MyEditorToolbarButton")->GetBaseDir() / TEXT("Resources"));

	Style->Set("MyEditorToolbarButton.PluginAction", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon20x20));
	return Style;
}

void FMyEditorToolbarButtonStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FMyEditorToolbarButtonStyle::Get()
{
	return *StyleInstance;
}
