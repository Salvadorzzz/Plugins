// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "MyEditorToolbarButtonStyle.h"

class FMyEditorToolbarButtonCommands : public TCommands<FMyEditorToolbarButtonCommands>
{
public:

	FMyEditorToolbarButtonCommands()
		: TCommands<FMyEditorToolbarButtonCommands>(TEXT("MyEditorToolbarButton"), NSLOCTEXT("Contexts", "MyEditorToolbarButton", "MyEditorToolbarButton Plugin"), NAME_None, FMyEditorToolbarButtonStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
