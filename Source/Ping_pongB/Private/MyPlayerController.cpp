// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{
  
}

void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    InputComponent->BindAction("Right",IE_Repeat, this, &AMyPlayerController::Right);
    InputComponent->BindAction("Left", IE_Repeat, this, &AMyPlayerController::Left);
}
void AMyPlayerController::Right()
{
    APlatformPawn* PlatformPawn = Cast<APlatformPawn>(GetPawn());

    if (PlatformPawn)
    {
        PlatformPawn->MoveRight();
    }
}
void AMyPlayerController::Left()
{
    APlatformPawn* PlatformPawn = Cast<APlatformPawn>(GetPawn());

    if (PlatformPawn)
    {
        PlatformPawn->MoveLeft();
    }
}
