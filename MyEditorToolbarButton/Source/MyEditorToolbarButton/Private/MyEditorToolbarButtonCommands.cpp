// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyEditorToolbarButtonCommands.h"

#define LOCTEXT_NAMESPACE "FMyEditorToolbarButtonModule"

void FMyEditorToolbarButtonCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "MyEditorToolbarButton", "Execute MyEditorToolbarButton action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
