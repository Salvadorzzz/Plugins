// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "MyBlankPluginStyle.h"

class FMyBlankPluginCommands : public TCommands<FMyBlankPluginCommands>
{
public:

	FMyBlankPluginCommands()
		:TCommands< FMyBlankPluginCommands>(TEXT("MyBlankPlugin"), NSLOCTEXT("Contexts", "MyBlankButton", "MyBlankButton Plugin"), NAME_None, FMyBlankPluginStyle::GetStyleSetName())

	{
	}

		virtual void RegisterCommands() override;

public:
	TSharedPtr<FUICommandInfo> PluginAction;

};