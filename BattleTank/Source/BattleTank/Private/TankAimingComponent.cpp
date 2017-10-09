// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankBarrelComponent.h"
#include "TankTurretComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingComponent::AimAt(FVector WorldSpaceAim, float LaunchSpeed)
{
	if (!Barrel || !Turret) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("ProjectileSpawn"));

	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, WorldSpaceAim, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace)) {
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
		RotateTurret(AimDirection);
	}
}

void UTankAimingComponent::SetBarrelReference(UTankBarrelComponent* NewBarrel)
{
	Barrel = NewBarrel;
}

void UTankAimingComponent::SetTurretReference(UTankTurretComponent* NewTurret)
{
	Turret = NewTurret;
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	auto TargetPitch = AimDirection.ToOrientationRotator().Pitch;
	Barrel->Elevate(TargetPitch);
}

void UTankAimingComponent::RotateTurret(FVector AimDirection)
{
	auto TargetYaw = AimDirection.ToOrientationRotator().Yaw;
	Turret->Rotate(TargetYaw);
}

