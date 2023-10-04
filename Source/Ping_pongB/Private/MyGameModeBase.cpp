// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
    // ���������� ������ ������ � ����
    DefaultPawnClass = APlatformPawn::StaticClass();
    // �������� BP-����� ��� ������
    PlayerControllerClass = AMyPlayerController::StaticClass();
    // �������� BP-����� ��� ����
    bWaitingForPlayers = true;
}

void AMyGameModeBase::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    // ���������, ������� ������� ����������, � ������� ���� ��� ����������� ������� ������
    // �������� ����������� �� ����� ��� � ��� �������� ������ �����
}