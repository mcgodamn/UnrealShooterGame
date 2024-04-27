// Fill out your copyright notice in the Description page of Project Settings.


#include "FuckEmAllGameMode.h"
#include "ShooterPlayerController.h"
#include "EngineUtils.h"
#include "ShooterAIController.h"


void AFuckEmAllGameMode::PawnDead(APawn* pawn)
{
    Super::PawnDead(pawn);

    if (auto controller = Cast<AShooterPlayerController>(pawn->GetController()))
    {
        EndGame(false);
    }
    else if (Cast<AShooterAIController>(pawn->GetController()))
    {
        for(auto aiCtrler : TActorRange<AShooterAIController>(GetWorld()))
        {
            if (!aiCtrler->IsDead()) return;
        }
        
        EndGame(true);
    }
}

void AFuckEmAllGameMode::EndGame(bool isPlayerWin)
{
    Super::EndGame(isPlayerWin);

    for(auto controller : TActorRange<APlayerController>(GetWorld()))
    {
        bool isCtrlerWin = controller->IsPlayerController() == isPlayerWin;
        controller->GameHasEnded(controller->GetPawn(), isCtrlerWin);
    }

}
