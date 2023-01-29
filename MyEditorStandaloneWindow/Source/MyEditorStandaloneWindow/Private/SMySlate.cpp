// Fill out your copyright notice in the Description page of Project Settings.


#include "SMySlate.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMySlate::Construct(const FArguments& InArgs)
{

	//为成员变量赋值
	IsFocusable = InArgs._IsFocusable;
	OnMyClicked = InArgs._OnMyClicked;
	
	ChildSlot
		[
			// Populate the widget
			SNew(SButton)
			.OnClicked(FOnClicked::CreateRaw(this, &SMySlate::OnClicked))
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SMySlate::OnClicked()
{
	if (OnMyClicked.IsBound())
	{
		FReply Reply = OnMyClicked.Execute();
	}
	return FReply::Handled();
}
