// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <functional>
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "MenuButton.generated.h"

UCLASS()
class MENUOTK_API UMenuButton : public UUserWidget
{
	GENERATED_BODY()
public:
    virtual bool Initialize() override;

    void OnClick(std::function<void()>);

    UFUNCTION()
    void Click();

    UTextBlock* Text() { return m_text; }

    UPROPERTY(BLueprintReadWrite, meta = (BindWidget))
    UButton* ButtonCustom = nullptr;

    UPROPERTY(BLueprintReadWrite, meta = (BindWidget))
    UTextBlock* m_text = nullptr;

private:
    std::function<void()> on_click_;	
};
