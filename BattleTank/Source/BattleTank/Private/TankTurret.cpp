// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::TurretSpin(float TurningSpeed)
{
	TurningSpeed = FMath::Clamp<float>(TurningSpeed, -1.f, 1.f);
	auto RotationChange = TurningSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0 , RawNewRotation , 0));
}



