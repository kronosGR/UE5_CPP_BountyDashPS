// Fill out your copyright notice in the Description page of Project Settings.


#include "BountyDashObject.h"

#include "UE5_CPP_BountyDashPS.h"
#include "UE5_CPP_BountyDashPSGameModeBase.h"

// Sets default values
ABountyDashObject::ABountyDashObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	check(Collider);
	RootComponent = Collider;
	Collider->SetCollisionProfileName("OverlapAllDynamic");

	OnActorBeginOverlap.AddDynamic(this, &ABountyDashObject::MyOnActorOverlap);
	OnActorEndOverlap.AddDynamic(this, &ABountyDashObject::MyOnActorEndOverlap);
}

// Called when the game starts or when spawned
void ABountyDashObject::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABountyDashObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float gameSpeed = GetCustomGameMode<AUE5_CPP_BountyDashPSGameModeBase>(GetWorld())->GetInvGameSpeed();

	AddActorLocalOffset(FVector(gameSpeed, 0.f, 0.f));
	if (GetActorLocation().X < KillPoint)
	{
		Destroy();
	}
}

void ABountyDashObject::SetKillPoint(float point)
{
	KillPoint = point;
}

float ABountyDashObject::GetKillPoint()
{
	return KillPoint;
}

void ABountyDashObject::MyOnActorOverlap(AActor* Actor, AActor* otherActor)
{
}

void ABountyDashObject::MyOnActorEndOverlap(AActor* Actor, AActor* otherActor)
{
}
