// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAIController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankPlayerController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AITank = GetAIControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (!AITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("The Tank is not possessed"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("The Tank is possessed by: %s"), *(AITank->GetName()));
			if (!PlayerTank)
			{
				UE_LOG(LogTemp, Warning, TEXT("AI Cannot find PlayerController"));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("AI found PlayerController: %s"), *(PlayerTank->GetName()))
			}
	}
}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (GetAIControlledTank()) 
	{
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}