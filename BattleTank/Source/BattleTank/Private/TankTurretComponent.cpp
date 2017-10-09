// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurretComponent.h"

void UTankTurretComponent::Rotate(float TargetYaw) {
	auto MaxMovementThisFrame = MaxDegreesPerSecond * GetWorld()->GetDeltaSeconds();
	float NewYaw;
	if (TargetYaw > RelativeRotation.Yaw) {
		NewYaw = FMath::Min(TargetYaw, RelativeRotation.Yaw + MaxMovementThisFrame);
	}
	else {
		NewYaw = FMath::Max(TargetYaw, RelativeRotation.Yaw - MaxMovementThisFrame);
	}

	SetRelativeRotation(FRotator(0.0f, NewYaw, 0.0f));
}


