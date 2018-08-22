// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Engine/World.h"




void UTankTrack::SetThrottle(float ThrottleSpeed)
{
	auto Name = GetName();
	//auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT(" %s Throttle: %f"), *Name, ThrottleSpeed);
}