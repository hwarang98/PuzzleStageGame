// Fill out your copyright notice in the Description page of Project Settings.


#include "Movers/MovingMoverActor.h"

AMovingMoverActor::AMovingMoverActor()
{
}

void AMovingMoverActor::BeginPlay()
{
	Super::BeginPlay();
}

void AMovingMoverActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsActive)
	{
		FVector CurrentLocation = GetActorLocation();
		FVector MoveOffset = Direction * MoveSpeed * DeltaTime;
		FVector NextLocation = CurrentLocation + MoveOffset;
		
		CurrentDistanceMoved += MoveOffset.Size();

		if (CurrentDistanceMoved >= MaxRange)
		{
			Direction *= -1;
			CurrentDistanceMoved = 0.f;
		}

		SetActorLocation(NextLocation);
	}
}
