// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "Engine/TargetPoint.h"
#include "GameFramework/Actor.h"
#include "ObstacleSpawner.generated.h"

UCLASS()
class UE5_CPP_BOUNTYDASHPS_API AObstacleSpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AObstacleSpawner();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	void SpawnObstacle();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<AObstacle>> ObstaclesToSpawn;

	UPROPERTY()
	TArray<ATargetPoint*> SpawnTargets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnTimer;

	UPROPERTY()
	USceneComponent* scene;

private:
	float KillPoint;
	float SpawnPoint;
	float TimeSinceLastSpawn;
};
