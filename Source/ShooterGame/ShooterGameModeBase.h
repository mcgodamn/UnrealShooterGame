// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShooterGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API AShooterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void PawnDead(class APawn* pawn);

protected:
	virtual void EndGame(bool isPlayerWin);
};
