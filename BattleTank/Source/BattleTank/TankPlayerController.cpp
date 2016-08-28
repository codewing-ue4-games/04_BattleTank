// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"




ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
	
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Tank not found!"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("Tank found: %s"), *(ControlledTank->GetName()));
	}
}
