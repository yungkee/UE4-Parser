// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuWidget.h"

void UMenuWidget::Setup()
{
	this->AddToViewport();

	UWorld* World = GetWorld();
	APlayerController* PlayerController = World->GetFirstPlayerController();


	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(this->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PlayerController->SetInputMode(InputModeData);

	PlayerController->bShowMouseCursor = true;
}

void UMenuWidget::RemoveWidget()
{
	this->RemoveFromViewport();

	UWorld* World = GetWorld();
	APlayerController* PlayerController = World->GetFirstPlayerController();

	FInputModeGameOnly InputModeData;
	PlayerController->SetInputMode(InputModeData);

	PlayerController->bShowMouseCursor = false;
}

void UMenuWidget::SetMenuInterface(IMenuInterface* MenuInterface)
{
	this->MenuInterface = MenuInterface;
}

