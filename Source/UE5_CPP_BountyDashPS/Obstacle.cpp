// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"

#include "UE5_CPP_BountyDashPS.h"
#include "UE5_CPP_BountyDashPSGameModeBase.h"

// Sets default values
AObstacle::AObstacle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	check(Collider);

	RootComponent = Collider;
	Collider->SetCollisionProfileName("OverlapAllDynamic");

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	check(Mesh);
	Mesh->AttachToComponent(Collider, FAttachmentTransformRules::KeepRelativeTransform);
	Mesh->SetCollisionResponseToChannels(ECR_Ignore);
	KillPoint = -20000.f;

	OnActorBeginOverlap.AddDynamic(this, &AObstacle::MyOnActorOverlap);
	OnActorEndOverlap.AddDynamic(this, &AObstacle::MyOnActorEndOverlap);
}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float gameSpeed = GetCustomGameMode<AUE5_CPP_BountyDashPSGameModeBase>(GetWorld())->GetInvGameSpeed();

	AddActorLocalOffset(FVector(gameSpeed, 0.f, 0.f));
	if (GetActorLocation().X < KillPoint)
	{
		Destroy();
	}
}

void AObstacle::SetKillPoint(float point)
{
	KillPoint = point;
}

float AObstacle::GetKillPoint()
{
	return KillPoint;
}

void AObstacle::MyOnActorOverlap(AActor* actor, AActor* otherActor)
{
}

void AObstacle::MyOnActorEndOverlap(AActor* actor, AActor* otherActor)
{
}
