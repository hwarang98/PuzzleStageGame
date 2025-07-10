// Fill out your copyright notice in the Description page of Project Settings.

#include "Movers/MoveActorBase.h"

AMoveActorBase::AMoveActorBase()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SkeletonComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletonMeshComponent"));

	RootComponent = SkeletonComponent;
	MeshComponent->SetupAttachment(GetRootComponent());

	MeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MeshComponent->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	MeshComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

	// SkeletonComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	// SkeletonComponent->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	// SkeletonComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	
}

void AMoveActorBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMoveActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

