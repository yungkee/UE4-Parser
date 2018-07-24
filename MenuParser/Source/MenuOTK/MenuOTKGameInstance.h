// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "MenuOTKGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MENUOTK_API UMenuOTKGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:
	UMenuOTKGameInstance(const FObjectInitializer & ObjectInitializer);

	virtual void Init();

	UFUNCTION(BlueprintCallable)
	void LoadMenu();



	virtual void LoadMainMenu() override;

private:
	TSubclassOf<class UUserWidget> MenuClass;


	class UMainMenu* Menu;

};
