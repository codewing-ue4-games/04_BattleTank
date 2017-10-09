// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrelComponent.generated.h"

/**
 * Holds the barrel and some specific options
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrelComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float TargetPitch);
	
	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 10.0f;

	UPROPERTY(EditAnywhere)
	float MaxElevationDegrees = 40.0f;
	UPROPERTY(EditAnywhere)
	float MinElevationDegrees = 0.0f;
	
};
