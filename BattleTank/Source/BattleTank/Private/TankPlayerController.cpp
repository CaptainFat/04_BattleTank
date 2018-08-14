// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}

ATank* ATankPlayerController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());

}


void ATankPlayerController::Tick(float delta) 
{
	Super::Tick(delta);
}

// Start the tank moving the barrel so that a shot would hit where
//The crosshair intersects the world
void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	// Get world location if linetrace through crosshari
	// If it hits the landscape 
		// Tell controlled tank to aim at this point
}