// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "PlatformPawn.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PING_PONGB_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	virtual void PostLogin(APlayerController* NewPlayer) override;
public:
	UFUNCTION(BlueprintCallable, Category = "MyCategory")
	bool getWaitingPlayer();
private:
	bool bWaitingForPlayers;
public:
	AMyGameModeBase();
};
