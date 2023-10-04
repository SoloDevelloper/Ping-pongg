// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "PlatformPawn.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PING_PONGB_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AMyPlayerController();
	void SetupInputComponent();
	void Right();
	void Left();
};
