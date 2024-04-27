// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PlayerCharacter.h"

void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();
    
    if (BehaviorTree)
    {
        RunBehaviorTree(BehaviorTree);
        Blackboard = GetBlackboardComponent();
        Blackboard->SetValueAsVector("StartLocation", GetPawn()->GetActorLocation());
    }
}

void AShooterAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    // if (BehaviorTree)
    // {
    //     auto player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    //     if (LineOfSightTo(player))
    //     {
    //         Blackboard->SetValueAsVector("PlayerLocation", player->GetActorLocation());
    //         Blackboard->SetValueAsVector("LastPlayerLocation", player->GetActorLocation());
    //     }
    //     else
    //     {
    //         Blackboard->ClearValue("PlayerLocation");
    //     }
    // }
}

bool AShooterAIController::IsDead() const
{
    return Cast<APlayerCharacter>(GetPawn())->IsDead();
}
