// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5f;
	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.35f;
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0f; //10km

	void AimAtCrosshair();
	bool GetSightRayHitLocation(FVector &HitLocation) const;
	ATank* GetControlledTank() const;
	bool GetLookVectorHitLocation(FVector CameraWorldDirection, FVector &HitLocation) const;

public: 
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
