// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AITank = GetAIControlledTank();
	if (!AITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("The Tank is not possessed"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("The Tank is possessed by: %s"), *(AITank->GetName()));
	}

}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
