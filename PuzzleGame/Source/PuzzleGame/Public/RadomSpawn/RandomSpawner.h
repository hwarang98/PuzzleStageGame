// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomSpawner.generated.h"

class UBoxComponent;
class ARadomSpawnActor;
struct FTimerHandle;

UCLASS()
class PUZZLEGAME_API ARandomSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ARandomSpawner();
	
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	UBoxComponent* SpawnVolume;
	

private:
	// UPROPERTY(EditAnywhere, Category = "Spawner")
	// TSubclassOf<ARadomSpawnActor> SpawnClass;
	
	FTimerHandle MoveTimerHandle;
	
	UPROPERTY(EditAnywhere, Category = "Spawner")
	float SpawnInterval = 5.f;  // 몇 초마다 스폰할지 (에디터에서 설정 가능)
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveInterval = 3.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector MoveRange = FVector(200.f, 200.f, 0.f);

	UPROPERTY(EditAnywhere, Category = "Lifetime")
	float Lifetime = FMath::RandRange(0.1f, 2.f);;  // 몇 초 후 소멸


// public:
// 	FORCEINLINE TSubclassOf<ARadomSpawnActor> GetSpawnClass() const { return SpawnClass; }
	
};
