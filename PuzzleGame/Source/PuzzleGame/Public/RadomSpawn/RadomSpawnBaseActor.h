// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RadomSpawnBaseActor.generated.h"

class UStaticMesh;
class UStaticMeshComponent;
class UParticleSystemComponent;

UCLASS()
class PUZZLEGAME_API ARadomSpawnBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARadomSpawnBaseActor();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category = "Spawner")
	UStaticMesh* MeshToSpawn;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USphereComponent* SphereComp;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMeshComp;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UParticleSystemComponent* ParticleComp;
	
	FTimerHandle SpawnTimerHandle;
	
	UPROPERTY(EditAnywhere, Category = "Spawner")
	float SpawnInterval = 3.f;  // 기본값

	UPROPERTY(EditAnywhere, Category = "Spawner")
	float DestroyDelay = 3.f;   // 기본값

	UFUNCTION()
	void SpawnActor();

public:
	FORCEINLINE UStaticMesh* GetSpawnClass() const { return MeshToSpawn; }
	


};
