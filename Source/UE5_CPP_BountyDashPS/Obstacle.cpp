// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"

#include "UE5_CPP_BountyDashPS.h"
#include "UE5_CPP_BountyDashPSGameModeBase.h"

// Sets default values
AObstacle::AObstacle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	check(Mesh);
	Mesh->AttachToComponent(Collider, FAttachmentTransformRules::KeepRelativeTransform);
	Mesh->SetCollisionResponseToChannels(ECR_Ignore);	

}

