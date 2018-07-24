// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"

#include "Runtime/UMG/Public/Components/WidgetSwitcher.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "Runtime/UMG/Public/Components/CanvasPanel.h"
#include "Runtime/UMG/Public/Components/CanvasPanelSlot.h"
#include "Runtime/UMG/Public/Components/NamedSlot.h"
#include "Runtime/UMG/Public/Components/HorizontalBox.h"
#include "Runtime/UMG/Public/Components/ScrollBox.h"
#include "MenuSystem/MenuButton.h"

#include "MainMenu.generated.h"


UCLASS()
class MENUOTK_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()
protected:

	virtual bool Initialize();
    
private:
    UPROPERTY(meta = (BindWidget))
    class UWidgetSwitcher* MenuSwitcher;

protected:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menu OTK")
    TSubclassOf<UMenuButton> BP_AutoButton;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    UCanvasPanel* Panel = nullptr;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    UHorizontalBox* BoxMenu = nullptr;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    UScrollBox* ScrollMenu = nullptr;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    UNamedSlot* ButtonQuit = nullptr;

public:

    void Quit_Function();


   /* UFUNCTION(BlueprintCallable, Category = "Output streaming")
    static void LaunchURL(const TCHAR* URL, const TCHAR* Parms, FString* Error);*/

};
