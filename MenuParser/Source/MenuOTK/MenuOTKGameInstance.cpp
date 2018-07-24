// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuOTKGameInstance.h"

#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "MenuSystem/MainMenu.h"
#include "MenuSystem/MenuWidget.h"

UMenuOTKGameInstance::UMenuOTKGameInstance(const FObjectInitializer & ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	MenuClass = MenuBPClass.Class;
}

void UMenuOTKGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Found class %s"), *MenuClass->GetName());
}

void UMenuOTKGameInstance::LoadMenu()
{
	Menu = CreateWidget<UMainMenu>(this, MenuClass);
	Menu->Setup();

	Menu->SetMenuInterface(this);
}


void UMenuOTKGameInstance::LoadMainMenu()
{
	APlayerController* PlayerController = GetFirstLocalPlayerController();
    
	PlayerController->ClientTravel("/Game/MenuSystem/WBP_MainMenu", ETravelType::TRAVEL_Absolute);
}
