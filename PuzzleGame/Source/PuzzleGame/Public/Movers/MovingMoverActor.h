// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Movers/MoveActorBase.h"
#include "MovingMoverActor.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEGAME_API AMovingMoverActor : public AMoveActorBase
{
	GENERATED_BODY()

	
public:	
	AMovingMoverActor();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	FVector Direction = FVector(1.f, 0.f, 0.f); // X축 방향으로 이동

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float MoveSpeed = 200.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	FVector StartLocation = FVector(0.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float MaxRange = 300.f;

	private:
	float CurrentDistanceMoved;
	
};
