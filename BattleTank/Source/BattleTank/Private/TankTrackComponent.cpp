// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrackComponent.h"


void UTankTrackComponent::SetThrottle(float Throttle)
{
	Throttle = FMath::Clamp(Throttle, -1.0f, 1.0f);

	auto AppliedForce = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(AppliedForce, ForceLocation);
}

