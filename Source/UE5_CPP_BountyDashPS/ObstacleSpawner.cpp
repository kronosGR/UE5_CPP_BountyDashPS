// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleSpawner.h"

#include "EngineUtils.h"
#include "Floor.h"
#include "UE5_CPP_BountyDashPS.h"
#include "UE5_CPP_BountyDashPSGameModeBase.h"

// Sets default values
AObstacleSpawner::AObstacleSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	check(Scene);
	RootComponent = Scene;

	SpawnTimer = 1.5f;
}

// Called when the game starts or when spawned
void AObstacleSpawner::BeginPlay()
{
	Super::BeginPlay();

	for (TActorIterator<ATargetPoint> TargetIter(GetWorld()); TargetIter; ++TargetIter)
	{
		SpawnTargets.Add(*TargetIter);
	}

	for (TActorIterator<AFloor> FloorIter(GetWorld()); FloorIter; ++FloorIter)
	{
		if (FloorIter->GetWorld() == GetWorld())
		{
			KillPoint = FloorIter->GetKillPoint();
			SpawnTimer = FloorIter->GetSpawnPoint();
		}
		TimeSinceLastSpawn = SpawnTimer;
	}
}

// Called every frame
void AObstacleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float trueSpawnTime = SpawnTimer / (float)GetCustomGameMode<AUE5_CPP_BountyDashPSGameModeBase>(GetWorld())->
		GetGameLevel();

	if (TimeSinceLastSpawn > trueSpawnTime)
	{
		TimeSinceLastSpawn = 0.f;
		SpawnObstacle();
	}
}

void AObstacleSpawner::SpawnObstacle()
{
	if (SpawnTargets.Num() > 0 && ObstaclesToSpawn.Num() > 0)
	{
		short Spawner = FMath::Rand() % SpawnTargets.Num();
		short Obstical = FMath::Rand() % ObstaclesToSpawn.Num();
		float CapsuleOffset = 0.f;

		FActorSpawnParameters SpawnInfo;

		FTransform myTrans = SpawnTargets[Spawner]->GetTransform();
		myTrans.SetLocation(FVector(SpawnPoint, myTrans.GetLocation().Y, myTrans.GetLocation().Z));

		AObstacle* newObs = GetWorld()->SpawnActor<AObstacle>(ObstaclesToSpawn[Obstical], myTrans,SpawnInfo);
		if (newObs)
		{
			newObs->SetKillPoint(KillPoint);
			USphereComponent* obsSphere = Cast<USphereComponent>(newObs->GetComponentByClass(USphereComponent::StaticClass()));

			if (obsSphere)
			{
				newObs->AddActorLocalOffset(FVector(0.f, 0.f, obsSphere->GetUnscaledSphereRadius()));
			}
		}
	}
}
