// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.2f;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0f; //10km

	void AimAtCrosshair();
	bool GetSightRayHitLocation(FVector &HitLocation) const;
	ATank* GetControlledTank() const;
	bool GetLookVectorHitLocation(FVector CameraWorldDirection, FVector &HitLocation) const;

public: 
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
