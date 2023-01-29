// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
//声明带返回值代理类型
DECLARE_DELEGATE_RetVal( FReply , FOnButtonClicked )


class MYEDITORSTANDALONEWINDOW_API SMySlate : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMySlate)
		: _IsFocusable ( false )
	{}

	SLATE_ARGUMENT(bool, IsFocusable)
	SLATE_EVENT( FOnButtonClicked , OnMyClicked )    //在FArguments中声明

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	bool  IsFocusable;

	//声明代理成员变量
	FOnButtonClicked OnMyClicked;

	FReply OnClicked();
};
