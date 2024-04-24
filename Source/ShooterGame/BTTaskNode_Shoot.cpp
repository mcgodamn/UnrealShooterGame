// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTaskNode_Shoot.h"
#include "AIController.h"
#include "PlayerCharacter.h"


UBTTaskNode_Shoot::UBTTaskNode_Shoot()
{
    NodeName = "Shoot";
}

EBTNodeResult::Type UBTTaskNode_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);
    Cast<APlayerCharacter>(OwnerComp.GetAIOwner()->GetPawn())->Shoot();
    
    return EBTNodeResult::Succeeded;
}
