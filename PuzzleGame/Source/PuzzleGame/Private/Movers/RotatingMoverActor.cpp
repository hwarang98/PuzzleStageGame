// Fill out your copyright notice in the Description page of Project Settings.


#include "Movers/RotatingMoverActor.h"

ARotatingMoverActor::ARotatingMoverActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARotatingMoverActor::BeginPlay()
{
	Super::BeginPlay();
}

void ARotatingMoverActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsActive)
	{
		FRotator Rotation = FRotator(0.f, RotationSpeed * DeltaTime, 0.f);
		AddActorLocalRotation(Rotation);
	}
}
