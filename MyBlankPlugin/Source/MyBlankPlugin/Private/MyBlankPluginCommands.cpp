// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlankPluginCommands.h"

#define LOCTEXT_NAMESPACE "FMyBlankPluginModule"

void FMyBlankPluginCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "FMyBlankPlugin", "Bring up FMyBlankPlugin window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
