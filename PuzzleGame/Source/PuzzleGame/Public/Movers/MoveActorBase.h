// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveActorBase.generated.h"

UCLASS()
class PUZZLEGAME_API AMoveActorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AMoveActorBase();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent* SkeletonComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	bool bIsActive = true;
};
