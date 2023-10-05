// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
    DefaultPawnClass = APlatformPawn::StaticClass();

    PlayerControllerClass = AMyPlayerController::StaticClass();

    bWaitingForPlayers = true;

}

void AMyGameModeBase::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);
    if (NewPlayer && NewPlayer->IsLocalPlayerController())
    {
        AMyPlayerController* PlayerController = Cast<AMyPlayerController>(NewPlayer);

        if (PlayerController)
        {
            if (GetNumPlayers() < 2)
            {
                GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Wait for player"));
            }
        }
    }
    if (GetNumPlayers() >= 2)
    {
        bWaitingForPlayers = false;
        FName ActorNameToFind = FName(TEXT("Ball"));
        TArray<AActor*> FoundActors;
        UGameplayStatics::GetAllActorsWithTag(GetWorld(), ActorNameToFind, FoundActors);
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("%d"), GetNumPlayers()));
    }
}
bool AMyGameModeBase::getWaitingPlayer() {
    return bWaitingForPlayers;
}
