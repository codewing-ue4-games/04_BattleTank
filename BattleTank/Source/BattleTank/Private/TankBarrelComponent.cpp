// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrelComponent.h"

void UTankBarrelComponent::Elevate(float TargetPitch)
{	
	auto ClampedTargetPitch = FMath::Clamp<float>(TargetPitch, MinElevationDegrees, MaxElevationDegrees);

	UE_LOG(LogTemp, Warning, TEXT("(%s) AimDirection: %f"), *GetOwner()->GetName(), ClampedTargetPitch);
	
	SetRelativeRotation(FRotator(ClampedTargetPitch, 0.0f, 0.0f));
}


