// Fill out your copyright notice in the Description page of Project Settings.

#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Engine/DamageEvents.h"
#include "PlayerCharacter.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun"));
	SkeletalMesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(ShootFX, SkeletalMesh, TEXT("MuzzleFlashSocket"));
	UGameplayStatics::SpawnSoundAttached(ShootSound, SkeletalMesh, TEXT("MuzzleFlashSocket"));

	FVector Pos;
	FRotator Rot;
	auto ctrler = Cast<APawn>(GetOwner())->GetController();
	ctrler->GetPlayerViewPoint(Pos, Rot);
	
	auto End = Pos + Rot.Vector() * MaxRange;
	FHitResult HitResult;
	FCollisionQueryParams params;
	params.AddIgnoredActor(this);
	params.AddIgnoredActor(GetOwner());
	if (GetWorld()->LineTraceSingleByChannel(HitResult, Pos, End, ECollisionChannel::ECC_GameTraceChannel1, params))
	{
		// DrawDebugPoint(GetWorld(), HitResult.ImpactPoint, 3, FColor::Red, true);
		auto Dir = -Rot.Vector();

		FPointDamageEvent DamageEvent(Damage, HitResult, Dir, nullptr);
		if (Cast<APlayerCharacter>(HitResult.GetActor()))
		{
			UGameplayStatics::SpawnEmitterAtLocation(this, HitFX, HitResult.ImpactPoint, Dir.Rotation());
			HitResult.GetActor()->TakeDamage(Damage, DamageEvent, ctrler, this);
			UGameplayStatics::SpawnSoundAtLocation(this, HitCharSound, HitResult.ImpactPoint);
		}
		else
		{
			UGameplayStatics::SpawnSoundAtLocation(this, HitEnvSound, HitResult.ImpactPoint);
		}
	}
}