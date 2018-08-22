// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankPlayerController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}



void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto AITank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank) 
	{
		AITank->AimAt(PlayerTank->GetActorLocation());
		AITank->Fire();
	}
}