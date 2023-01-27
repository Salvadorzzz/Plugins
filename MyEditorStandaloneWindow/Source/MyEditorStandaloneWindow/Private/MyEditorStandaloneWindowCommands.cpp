// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyEditorStandaloneWindowCommands.h"

#define LOCTEXT_NAMESPACE "FMyEditorStandaloneWindowModule"

void FMyEditorStandaloneWindowCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "MyEditorStandaloneWindow", "Bring up MyEditorStandaloneWindow window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
