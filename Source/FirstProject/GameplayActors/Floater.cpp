// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));
	initialLocation = FVector(0.0f);
	placedLocation = FVector(0.0f);
	worldOrigin = FVector(0.0f, 0.0f, 0.0f);
	initialDirection = FVector(0.0f, 0.0f, 0.0f);
	bInitializeFloaterLocations = false;
	bShouldFloat = false;
	initialForce = FVector(2000000.0f, 0.0f, 0.0f);
	initialTorque = FVector(2000000.0f, 0.0f, 0.0f);
	runningTime = 0.f;

	A = 0.f;
	B = 0.f;
	C = 0.f;
	D = 0.f;
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();
	
	//FVector initialLocation = FVector(0.0f, 0.0f, 0.0f);
	
	/*float initialX = FMath::FRand();
	float initialY = FMath::FRand();
	float initialZ = FMath::FRand();*/
	float initialX = FMath::FRandRange(-500.f, 500.f);
	float initialY = FMath::FRandRange(-500.f, 500.f);
	float initialZ = FMath::FRandRange(0.f, 500.f);

	//FVector initialLocation = FVector(initialX, initialY, initialZ);
	initialLocation.X = initialX;
	initialLocation.Y = initialY;
	initialLocation.Z = initialZ;

	//initialLocation *= 500.f; //scale x,y,z by 20 so rand is between 0 - 20 instead of 0 - 1

	placedLocation = GetActorLocation();
	
	if(bInitializeFloaterLocations)
		SetActorLocation(initialLocation);

	baseZLocation = placedLocation.Z;

	//FHitResult hitResult;
	//FVector LocalOffset = FVector(200.0f, 0.0f, 0.0f);
	//AddActorLocalOffset(LocalOffset, true, &hitResult);
	//AddActorWorldOffset(LocalOffset, true, &hitResult);

	
	//StaticMesh->AddForce(initialForce);
	//StaticMesh->AddTorqueInRadians(initialTorque);
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*if (bShouldFloat)
	{
		FHitResult hitResult;
		AddActorLocalOffset(initialDirection, true, &hitResult);

		FVector hitLocation = hitResult.Location;

		//UE_LOG(LogTemp, Warning, TEXT("Hit Location: X = %f, Y = %f, Z = %f"), hitLocation.X, hitLocation.Y, hitLocation.Z);
	}*/
	//FRotator Rotation = FRotator(0.0f, 1.0f, 0.0f);
	//AddActorLocalRotation(Rotation);
	//AddActorWorldRotation(Rotation);

	if (bShouldFloat)
	{
		FVector newLocation = GetActorLocation();
		newLocation.Z = baseZLocation + A * FMath::Sin(B * runningTime - C) + D;

		SetActorLocation(newLocation);
		runningTime += DeltaTime;
	}
}

