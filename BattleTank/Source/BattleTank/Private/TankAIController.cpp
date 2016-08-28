// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	ATank* ControlledTank = GetPlayerTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank not found!"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank found: %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) {
		return nullptr;
	} else {
		return Cast<ATank>(PlayerTank);
	}
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) { 
		GetPlayerTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

