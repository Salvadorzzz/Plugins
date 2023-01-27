// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "MyEditorStandaloneWindowStyle.h"

class FMyEditorStandaloneWindowCommands : public TCommands<FMyEditorStandaloneWindowCommands>
{
public:

	FMyEditorStandaloneWindowCommands()
		: TCommands<FMyEditorStandaloneWindowCommands>(TEXT("MyEditorStandaloneWindow"), NSLOCTEXT("Contexts", "MyEditorStandaloneWindow", "MyEditorStandaloneWindow Plugin"), NAME_None, FMyEditorStandaloneWindowStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};