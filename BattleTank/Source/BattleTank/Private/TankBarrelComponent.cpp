// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrelComponent.h"

void UTankBarrelComponent::Elevate(float TargetPitch)
{	
	auto MaxMovementThisFrame = MaxDegreesPerSecond * GetWorld()->GetDeltaSeconds();
	float NewPitch;
	if (TargetPitch > RelativeRotation.Pitch) {
		NewPitch = FMath::Min(TargetPitch, RelativeRotation.Pitch + MaxMovementThisFrame);
	} else {
		NewPitch = FMath::Max(TargetPitch, RelativeRotation.Pitch - MaxMovementThisFrame);
	}

	auto ClampedTargetPitch = FMath::Clamp<float>(NewPitch, MinElevationDegrees, MaxElevationDegrees);
	
	SetRelativeRotation(FRotator(ClampedTargetPitch, 0.0f, 0.0f));
}


