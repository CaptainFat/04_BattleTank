// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h "
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/Engine/Classes/Camera/PlayerCameraManager.h"
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

	AimTowardsCrosshair();
}

// Start the tank moving the barrel so that a shot would hit where
//The crosshair intersects the world
void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation; // Out Parameter
	if (GetSightRayHitLocation(HitLocation)) // Will linetrace 
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
		// If it hits the landscape 
		// Tell controlled tank to aim at this point
	}

}
// Get world location of linetrace through crosshair, ture if hits landscape
// Finds where the point is on the screen
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	FVector LookDirection;

	// "de-project' the screen position of the croshair to a world direction
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// Line trace along that look direction, and see what we hit
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
	return true;
} 

   // Finds what direction this point is looking on the world
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WorldCameraLocation;// To be Discarded
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		WorldCameraLocation,
		LookDirection
	);
}	

// Determins where in the world this point is touching the map
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
			)
		{
			HitLocation = HitResult.Location;
			return true;
		}
	else
		{
		HitLocation = FVector(0.0);
			return false; // Line trace didn't succeed
		}
}   
