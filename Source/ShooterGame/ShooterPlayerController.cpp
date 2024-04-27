// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    HUDInstance->RemoveFromParent();

    if (bIsWinner)
    {
        CreateWidget(this, WinUI)->AddToViewport();
    }
    else
    {
        CreateWidget(this, LoseUI)->AddToViewport();
    }

    GetWorldTimerManager().SetTimer(TimerHandle, this, &APlayerController::RestartLevel, RestartDelay);
}

void AShooterPlayerController::BeginPlay()
{
    HUDInstance = CreateWidget(this, HudUI);
    HUDInstance->AddToViewport();
}
