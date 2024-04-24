// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationIfSeen.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"


UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen()
{
    NodeName = "PlayerLocation if Seen";
}

void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    auto player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    auto Blackboard = OwnerComp.GetBlackboardComponent();
    if (OwnerComp.GetAIOwner()->LineOfSightTo(player))
    {
        Blackboard->SetValueAsVector(GetSelectedBlackboardKey(), player->GetActorLocation());
    }
    else
    {
        Blackboard->ClearValue(GetSelectedBlackboardKey());
    }
}
