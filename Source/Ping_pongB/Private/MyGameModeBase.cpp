// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
    // Установите классы игрока и мяча
    DefaultPawnClass = APlatformPawn::StaticClass();
    // Создайте BP-класс для игрока
    PlayerControllerClass = AMyPlayerController::StaticClass();
    // Создайте BP-класс для мяча
    bWaitingForPlayers = true;
}

void AMyGameModeBase::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    // Проверьте, сколько игроков подключено, и начните игру при подключении второго игрока
    // Выведите уведомление на экран или в лог ожидания начала матча
}