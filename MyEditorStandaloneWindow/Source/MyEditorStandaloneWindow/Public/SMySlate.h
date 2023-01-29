// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
//����������ֵ��������
DECLARE_DELEGATE_RetVal( FReply , FOnButtonClicked )


class MYEDITORSTANDALONEWINDOW_API SMySlate : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMySlate)
		: _IsFocusable ( false )
	{}

	SLATE_ARGUMENT(bool, IsFocusable)
	SLATE_EVENT( FOnButtonClicked , OnMyClicked )    //��FArguments������

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	bool  IsFocusable;

	//���������Ա����
	FOnButtonClicked OnMyClicked;

	FReply OnClicked();
};
