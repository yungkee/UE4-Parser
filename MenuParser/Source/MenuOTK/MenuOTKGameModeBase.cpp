// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuOTKGameModeBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/GameFramework/GameUserSettings.h"


void AMenuOTKGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    if (GEngine)
    {
        UGameUserSettings* MyGameSettings = GEngine->GetGameUserSettings();
        MyGameSettings->SetScreenResolution(FIntPoint(1024, 768));
        MyGameSettings->SetVSyncEnabled(true);
        MyGameSettings->ApplySettings(false);
    }

   
}
