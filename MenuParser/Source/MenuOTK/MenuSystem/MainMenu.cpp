// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"
#include "Runtime/Core/Public/Misc/FileHelper.h"

#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "MenuSystem/MenuButton.h"
#include "Runtime/Core/Public/GenericPlatform/GenericPlatformMisc.h"
#include "Runtime/Core/Public/Misc/Paths.h"
#include <string>
#include <vector>


void UMainMenu::Quit_Function()
{
    auto Button = CreateWidget<UMenuButton>(GetWorld(), BP_AutoButton);
    Button->OnClick([&]() { GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit"); });
    Button->Text()->SetText(FText::FromString("Quit"));
    ButtonQuit->SetContent(Button);
}

bool UMainMenu::Initialize()
{
    bool Success = Super::Initialize();
    if (!Success) return false;

    struct CommandArg
    {
        FString path_exe = "";
        FString button_name = "";
        FString path_args = "";
        CommandArg(FString url_, FString param_, FString name_) : button_name(name_), path_args(param_), path_exe(url_)
        {}
    };

    //parsing text file
    FString path = FPaths::ProjectDir() + "Content/cfg.ini";
    TArray<FString> lines;
    FString file;
    FFileHelper::LoadFileToString(file, *path);
    file.ParseIntoArray(lines, TEXT("\n"), false);
  
    TArray<CommandArg> commands;
    for (int32 i = 0; i < lines.Num(); i++)
    {
     FString parsString = lines[i];
     TArray<FString> array = {};

     parsString.ParseIntoArray(array, TEXT("="), false);

     FString button_name = array[0];
     parsString = array[1];
     parsString = parsString.Trim();
     parsString.ParseIntoArray(array, TEXT(" "), false);
     if (array.Num() > 0)
     {
      FString program_name = array[0];
      if (array.Num() > 1)
      {

        parsString.RemoveAt(0, array[0].Len(), true);
        wchar_t r = '\r';
        wchar_t w = ' ';
        parsString = parsString.Replace(&r, &w);
        commands.Add(CommandArg(program_name, parsString, button_name)); 
       }
       else
       {
        commands.Add(CommandArg(program_name, "", button_name));
       }  
     }
    }
    
    // create button based on text parsing input
    WidgetTree->RootWidget = Panel;
    for (int i = 0; i != commands.Num(); i++)
    {
        if (BP_AutoButton)
        {
         auto command_result = commands[i];
         auto Button = CreateWidget<UMenuButton>(GetWorld(), BP_AutoButton);
         Button->OnClick([this, command_result]()
        {
         UE_LOG(LogTemp, Warning, TEXT("url:%s title:%s pass:%s"), *command_result.path_exe, *command_result.button_name,*command_result.path_args);
         FProcHandle procHandle = FPlatformProcess::CreateProc(*command_result.path_exe, *command_result.path_args, false, false, false, NULL, NULL, 0, nullptr);
         });
         Button->Text()->SetText(FText::FromString(command_result.button_name));
         ScrollMenu->AddChild(Button);    
        }
    }
    //Quit Button
    Quit_Function();
  
    return true;
}


