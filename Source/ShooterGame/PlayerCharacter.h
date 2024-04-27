// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class SHOOTERGAME_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintPure)
	bool IsDead() const;
	UFUNCTION(BlueprintPure)
	float GetHPRatio() const;
	
	void Shoot();

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AGun> GunClass;
	
	UPROPERTY(EditDefaultsOnly)
	float MaxHp = 100;
	
	UPROPERTY(VisibleAnywhere)
	float Hp;
	
	class AGun* GunInstance;
};
