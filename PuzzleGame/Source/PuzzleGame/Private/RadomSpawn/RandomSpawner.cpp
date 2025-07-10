// Fill out your copyright notice in the Description page of Project Settings.


#include "RadomSpawn/RandomSpawner.h"
#include "Components/BoxComponent.h"
#include "Engine/TimerHandle.h"

// Sets default values
ARandomSpawner::ARandomSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));
 
	SpawnVolume->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void ARandomSpawner::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARandomSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

