// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SHOOTERGAME_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PullTrigger();

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;
	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* SkeletalMesh;
	
	UPROPERTY(EditAnywhere)
	class UParticleSystem* ShootFX;
	UPROPERTY(EditAnywhere)
	class UParticleSystem* HitFX;
	UPROPERTY(EditAnywhere)
	class USoundBase* ShootSound;
	UPROPERTY(EditAnywhere)
	class USoundBase* HitEnvSound;
	UPROPERTY(EditAnywhere)
	class USoundBase* HitCharSound;

	UPROPERTY(EditAnywhere)
	float MaxRange = 10000;
	
	UPROPERTY(EditAnywhere)
	float Damage = 10;
};
