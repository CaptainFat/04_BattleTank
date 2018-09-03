// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for Aiming State
UENUM(BlueprintType)
enum class EFiringStatus : uint8
{
	Realoding,
	Aiming,
	Locked
};


// Forward Declaration
class UTankBarrel; 
class UTankTurret;

// Holds barrel's properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	void AimAt(FVector HitLocation, float LaunchSpeed);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

private:
	UTankBarrel * Barrel = nullptr;

	UTankTurret * Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

	void MoveTurretTowards(FVector AimDirection);

	// Sets default values for this component's properties
	UTankAimingComponent();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Setup")
		EFiringStatus FiringStatus = EFiringStatus::Aiming;
};
