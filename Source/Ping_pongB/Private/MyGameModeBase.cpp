// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
    DefaultPawnClass = APlatformPawn::StaticClass();

    PlayerControllerClass = AMyPlayerController::StaticClass();
    bWaitingForPlayers = true;
    allPawns = GetPawnsOnScene();
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
        GetAllPlayerControllers();
        //GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("%d"), GetNumPlayers()));
    }
}
TArray<APawn*> AMyGameModeBase::GetPawnsOnScene()
{
    TArray<AActor*> FoundActors;
    TArray<APawn*> FoundPawns;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawn::StaticClass(), FoundActors);

    for (AActor* Actor : FoundActors)
    {
        APawn* Pawn = Cast<APawn>(Actor);
        if (Pawn)
        {
            FoundPawns.Add(Pawn);
        }
    }
    return FoundPawns;
}
bool AMyGameModeBase::getWaitingPlayer() {
    return bWaitingForPlayers;
}
void AMyGameModeBase::GetAllPlayerControllers() {

        TArray<AActor*>  PlayerControllers;

        UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerController::StaticClass(), PlayerControllers);
        int i = 0;
        for (AActor* PlayerController : PlayerControllers)
        {
            APlayerController* PlayerControllerr = Cast<APlayerController>(PlayerController);

            if (PlayerControllerr)
            {
                PlayerControllerr->Possess(allPawns[i]);
                i++;
            }
 






        }
 }