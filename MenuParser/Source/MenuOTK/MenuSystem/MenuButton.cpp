// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuButton.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "UObject/ConstructorHelpers.h"

bool UMenuButton::Initialize()
{
    auto success = Super::Initialize();

    WidgetTree->RootWidget = ButtonCustom;
    ButtonCustom->AddChild(m_text);

    return success;
}

void UMenuButton::OnClick(std::function<void()> fn)
{
    on_click_ = fn;
    ButtonCustom->OnClicked.AddDynamic(this, &UMenuButton::Click);
}

void UMenuButton::Click()
{
    on_click_();
}



