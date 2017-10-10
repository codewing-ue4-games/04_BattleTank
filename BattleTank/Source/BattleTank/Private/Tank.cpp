// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankBarrelComponent.h"
#include "Projectile.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation) {
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrelComponent* NewBarrel)
{
	TankAimingComponent->SetBarrelReference(NewBarrel);
	Barrel = NewBarrel;
}

void ATank::SetTurretReference(UTankTurretComponent* NewTurret)
{
	TankAimingComponent->SetTurretReference(NewTurret);
}

void ATank::Fire()
{
	if (!Barrel) { return; }

	bool CanFire = (GetWorld()->GetTimeSeconds() - LastFireTime) > ReloadTime;
	if (CanFire) {
		LastFireTime = GetWorld()->GetTimeSeconds();

		auto SpawnPosition = Barrel->GetSocketLocation(FName("ProjectileSpawn"));
		auto SpawnRotation = Barrel->GetSocketRotation(FName("ProjectileSpawn"));
		AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(Projectile, SpawnPosition, SpawnRotation);
		projectile->LaunchProjectile(LaunchSpeed);
	}
}

