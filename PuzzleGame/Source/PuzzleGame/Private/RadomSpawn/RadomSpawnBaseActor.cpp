// Fill out your copyright notice in the Description page of Project Settings.


#include "RadomSpawn/RadomSpawnBaseActor.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Engine/StaticMeshActor.h"


ARadomSpawnBaseActor::ARadomSpawnBaseActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	RootComponent = SphereComp;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	StaticMeshComp->SetupAttachment(SphereComp);

	ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComp"));
	ParticleComp->SetupAttachment(StaticMeshComp);

	StaticMeshComp->SetRelativeLocation(FVector(0.f, 0.f, -12.f));
	StaticMeshComp->SetRelativeScale3D(FVector(0.25f));

	// 이제 메시, 파티클 모두 에디터에서 설정 가능
}


void ARadomSpawnBaseActor::BeginPlay()
{
	Super::BeginPlay();
	SpawnInterval = FMath::FRandRange(3.f, 4.f);
	DestroyDelay = FMath::FRandRange(2.2f, 2.8f);

	GetWorld()->GetTimerManager().SetTimer(
		SpawnTimerHandle,
		this,
		&ThisClass::SpawnActor,
		SpawnInterval,
		true  // 반복 실행
	);
}

void ARadomSpawnBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARadomSpawnBaseActor::SpawnActor()
{
	if (!MeshToSpawn) return;

	auto SpawnedActor = GetWorld()->SpawnActor<AStaticMeshActor>(GetActorLocation(), GetActorRotation());
	if (!SpawnedActor) return;

	auto MeshComp = SpawnedActor->GetStaticMeshComponent();
	MeshComp->SetMobility(EComponentMobility::Movable);  // 여기서 Movable로 변경
	MeshComp->SetStaticMesh(MeshToSpawn);
	MeshComp->SetSimulatePhysics(false);
	MeshComp->SetEnableGravity(false);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MeshComp->SetCollisionProfileName(TEXT("BlockAll"));

	// 타이머 핸들 변수를 선언해서 넘겨야 함
	FTimerHandle DestroyHandle;
	GetWorld()->GetTimerManager().SetTimer(
		DestroyHandle,
		[SpawnedActor]()
		{
			if (IsValid(SpawnedActor))
				SpawnedActor->Destroy();
		},
		DestroyDelay,
		false
	);
}


