// Fill out your copyright notice in the Description page of Project Settings.

#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity(0.f,0.f,0.f);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	const FCollisionResponseParams ResponseParam;
	const TArray < AActor * > ActorsToIgnore;



	if (UGameplayStatics::SuggestProjectileVelocity(this,OutLaunchVelocity,StartLocation,HitLocation,LaunchSpeed,false,0.f,0.f,ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		auto TankName = GetOwner()->GetName();
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		UE_LOG(LogTemp, Warning, TEXT("%s is Aiming at %s"), *TankName, *AimDirection.ToString());
	}




}