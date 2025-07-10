// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MoveActorBase.h"
#include "RotatingMoverActor.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEGAME_API ARotatingMoverActor : public AMoveActorBase
{
	GENERATED_BODY()

public:	
	ARotatingMoverActor();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform Settings")
	float RotationSpeed = 90.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform Settings")
	float MoveSpeed = 200.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform Settings")
	float MaxRange = 300.f;
};
