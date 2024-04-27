// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterGameModeBase.h"
#include "FuckEmAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API AFuckEmAllGameMode : public AShooterGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void PawnDead(class APawn* pawn) override;
protected:
	virtual void EndGame(bool isPlayerWin) override;
};
