// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class UE5_CPP_BOUNTYDASHPS_API AObstacle : public AActor
{
	GENERATED_BODY()

	float KillPoint;

public:
	// Sets default values for this actor's properties
	AObstacle();

	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetKillPoint(float point);
	float GetKillPoint();

protected:
	UFUNCTION()
	virtual void MyOnActorOverlap(AActor* actor, AActor* otherActor);

	UFUNCTION()
	virtual void MyOnActorEndOverlap(AActor* actor, AActor* otherActor);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USphereComponent* Collider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;
};
